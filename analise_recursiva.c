#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

#define RESET "\033[0m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define RED "\033[1;31m"

// [H9] Cálculo Recursivo: Função para soma das tentativas usando recursividade
float soma_recursiva(int tentativas[], int n) {
    if (n <= 0) return 0;
    return tentativas[n - 1] + soma_recursiva(tentativas, n - 1);
}

// [H9] Cálculo Recursivo: Função para calcular variância (para o desvio padrão)
float variancia_recursiva(int tentativas[], int n, float media) {
    if (n <= 0) return 0;
    float diferenca = tentativas[n - 1] - media;
    return (diferenca * diferenca) + variancia_recursiva(tentativas, n - 1, media);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    // [H8] Leitura do histórico: Abre o arquivo gerado pelo H6
    FILE *arquivo = fopen("historico_partidas.txt", "r");
    if (arquivo == NULL) {
        printf(RED "\n[Erro] historico_partidas.txt não encontrado!\n" RESET);
        return 1;
    }
    
    int alvo_temp, tentativa_temp, score_temp;
    int alvos_array[100];
    int tentativas_array[100];
    int scores_array[100];
    int qtd_partidas = 0;
    
    // [H8] Leitura e [H21] Desmascarando os dados ofuscados
    while (fscanf(arquivo, "%d %d %d", &alvo_temp, &tentativa_temp, &score_temp) != EOF && qtd_partidas < 100) {
        // [H21] Subtrai 17 para restaurar a métrica legítima gravada pelo jogo
        alvos_array[qtd_partidas] = alvo_temp - 17;
        tentativas_array[qtd_partidas] = tentativa_temp - 17;
        scores_array[qtd_partidas] = score_temp - 17;
        qtd_partidas++;
    }
    fclose(arquivo);
    
    if (qtd_partidas == 0) {
        printf(YELLOW "\nHistórico vazio. Jogue uma partida primeiro.\n" RESET);
        return 0;
    }
    
    // Usando as funções do [H9]
    float soma = soma_recursiva(tentativas_array, qtd_partidas);
    float media = soma / qtd_partidas;
    float variancia_total = variancia_recursiva(tentativas_array, qtd_partidas, media);
    float desvio_padrao = sqrt(variancia_total / qtd_partidas);
    
    printf(CYAN "\n========================================\n");
    printf("         ESTATÍSTICAS GERAIS        \n");
    printf("========================================\n" RESET);
    printf("Partidas Jogadas: " GREEN "%d\n" RESET, qtd_partidas);
    printf("Média de tentativas: " YELLOW "%.2f\n" RESET, media);
    printf("Desvio Padrão: " YELLOW "%.2f\n" RESET, desvio_padrao);
    
    // [H10] Sistema de Insight: Sugestão baseada no resultado recursivo
    printf(CYAN "\n========================================\n" RESET);
    if (media < 7.0) {
        printf(YELLOW "💡 Dica do Sistema (H10):\nSua média é %.2f (menor que 7).\n", media);
        printf("Recomendamos utilizar a estratégia de 'Busca Binária' para otimizar os palpites!\n" RESET);
    } else {
        printf(GREEN "🎉 Excelente! Sua média é %.2f. Estratégia sólida!\n" RESET, media);
    }
    
    // [H20] Gráfico ASCII: Renderização do desempenho
    printf(CYAN "\n========================================\n");
    printf("       GRÁFICO DE DESEMPENHO ASCII      \n");
    printf("========================================\n" RESET);
    for (int i = 0; i < qtd_partidas; i++) {
        printf("P%02d | ", i + 1);
        for(int j = 0; j < tentativas_array[i]; j++) {
            printf(GREEN "■" RESET); // Bloco visual ASCII para o gráfico
        }
        printf(" (%d)\n", tentativas_array[i]);
    }

    // [H22] Exportar Relatório CSV: Criação do ficheiro separado por ponto e vírgula
    FILE *csv = fopen("relatorio_performance.csv", "w");
    if (csv != NULL) {
        fprintf(csv, "ID_Partida;Numero_Secreto;Tentativas;Score\n");
        for (int i = 0; i < qtd_partidas; i++) {
            fprintf(csv, "%d;%d;%d;%d\n", i + 1, alvos_array[i], tentativas_array[i], scores_array[i]);
        }
        fclose(csv);
        printf(CYAN "\n[+] Dados exportados com sucesso para 'relatorio_performance.csv'\n" RESET);
    }
    
    return 0;
}

// fim
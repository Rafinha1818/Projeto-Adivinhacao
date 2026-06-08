#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// [H18] Temas de Cores do Terminal: Variáveis globais para os Temas de Cores
char *C_RESET = "\033[0m", *C_RED = "\033[1;31m", *C_GREEN = "\033[1;32m";
char *C_YELLOW = "\033[1;33m", *C_CYAN = "\033[1;36m", *C_PURPLE = "\033[1;35m";

// [H14] Introdução Animada: Função que cria o efeito de digitação lenta
void efeito_digitar(char *texto, int velocidade) {
    for (int i = 0; texto[i] != '\0'; i++) {
        putchar(texto[i]);
        fflush(stdout);
        Sleep(velocidade);
    }
}

// [H15] Efeitos Sonoros Nativos: Funções que utilizam o Beep nativo do Windows
void som_vitoria() { Beep(523, 150); Beep(659, 150); Beep(784, 150); Beep(1046, 300); }
void som_derrota() { Beep(392, 300); Beep(349, 300); Beep(293, 400); }
void som_alerta() { Beep(880, 100); }

// [H18] Temas de Cores do Terminal: Menu para escolha dinâmica da paleta visual
void escolher_tema() {
    int opcao = 0;
    char linha[100];
    printf("Escolha o Tema Visual:\n1 - Classico (Cores Padrao)\n2 - Cyberpunk (Ciano e Roxo)\n3 - Alerta (Vermelho e Amarelo)\nEscolha: ");
    fgets(linha, sizeof(linha), stdin);
    sscanf(linha, "%d", &opcao);
    
    if (opcao == 2) {
        C_CYAN = "\033[1;35m"; C_YELLOW = "\033[1;36m"; C_GREEN = "\033[1;36m";
    } else if (opcao == 3) {
        C_CYAN = "\033[1;31m"; C_GREEN = "\033[1;33m"; C_PURPLE = "\033[1;31m";
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8); 
    srand(time(NULL)); 
    char linha[100]; 
    char jogar_novamente;
    
    // [H14] Introdução Animada: Limpando a tela e chamando a animação
    system("cls");
    printf("%s==================================================\n", C_CYAN);
    efeito_digitar("       INICIALIZANDO RETRO ARCADE SYSTEM...      \n", 15);
    printf("==================================================\n%s", C_RESET);
    Sleep(300);
    
    // Chamada do menu de cores (H18)
    escolher_tema();

    // [H13] Loop de Rejogabilidade: Estrutura do-while que mantem o jogo aberto
    do {
        int max_num = 100, limite_tentativas = -1, tempo_limite = -1; 
        int nivel = 0, modo = 0;
        int pontuacao_maxima = 1000; // Base para H16
        
        system("cls");
        // [H1] Interface de Boas-vindas e regras
        printf("%s\n========================================\n", C_CYAN);
        printf("       BEM-VINDO AO JOGO DE ADIVINHAÇÃO       \n");
        printf("========================================\n%s", C_RESET);
        
        // [H11] Níveis de Dificuldade & [H19] Intervalo Dinâmico Customizado
        while(nivel < 1 || nivel > 4) {
            printf("%s\nEscolha a Dificuldade:\n%s", C_YELLOW, C_RESET);
            printf("1 - Fácil (1 a 50)\n2 - Médio (1 a 100)\n3 - Difícil (1 a 500)\n");
            printf("4 - Customizado (Você define o limite máximo)\nSua escolha: "); // [H19]
            fgets(linha, sizeof(linha), stdin);
            sscanf(linha, "%d", &nivel);
        }
        
        if (nivel == 1) max_num = 50;
        else if (nivel == 3) max_num = 500;
        else if (nivel == 4) {
            // [H19] Lógica do Intervalo Dinâmico
            printf("%sDigite o número máximo do intervalo: %s", C_YELLOW, C_RESET);
            fgets(linha, sizeof(linha), stdin);
            sscanf(linha, "%d", &max_num);
            if(max_num < 10) max_num = 10; 
        } else max_num = 100;
        
        // Seleção de Modos - Incluindo H12 e H23
        while(modo < 1 || modo > 3) {
            printf("%s\nEscolha o Modo de Jogo:\n%s", C_YELLOW, C_RESET);
            printf("1 - Modo Normal Livre\n");
            printf("2 - Morte Súbita (7 tentativas)\n"); // [H12]
            printf("3 - Contra o Relógio (25 segundos)\n"); // [H23]
            printf("Sua escolha: ");
            fgets(linha, sizeof(linha), stdin);
            sscanf(linha, "%d", &modo);
        }
        
        if (modo == 2) limite_tentativas = 7; // Ativação [H12]
        if (modo == 3) tempo_limite = 25; // Ativação [H23]
        
        // [H2] Geração Aleatória: Sorteando o número baseado no limite escolhido
        int numero_secreto = (rand() % max_num) + 1;
        int palpite = 0, tentativas_gastas = 0, acertou = 0, tempo_esgotado = 0;
        int score_final = 0;

        printf("%s\n=> Pensei em um número entre 1 e %d. Adivinhe!\n%s", C_PURPLE, max_num, C_RESET);
        
        // Início da contagem de tempo para o [H23] Contra o Relógio
        time_t tempo_inicio = time(NULL);
        
        while (!acertou && !tempo_esgotado) {
            // [H12] Morte Súbita: Força a quebra do loop se atingir limite
            if (modo == 2 && tentativas_gastas >= limite_tentativas) break; 
            
            // [H3] Entrada de palpites do usuário
            printf("\nDigite seu palpite: ");
            fgets(linha, sizeof(linha), stdin);
            
            // [H23] Contra o Relógio: Verificação de estouro de tempo
            time_t tempo_atual = time(NULL);
            int tempo_passado = (int)difftime(tempo_atual, tempo_inicio);
            if (modo == 3 && tempo_passado >= tempo_limite) { tempo_esgotado = 1; break; }
            
            if (sscanf(linha, "%d", &palpite) != 1) continue;
            
            // [H17] Invalidação Inteligente: Bloqueia palpite fora do escopo sem gastar tentativa
            if (palpite < 1 || palpite > max_num) {
                printf("%s🚫 INVÁLIDO! O número está entre 1 e %d. Tentativa não penalizada.%s\n", C_RED, max_num, C_RESET);
                continue; // Volta ao início sem incrementar H5
            }
            
            // [H5] Contador de Tentativas
            tentativas_gastas++;
            
            if (palpite == numero_secreto) {
                acertou = 1;
                // [H16] Sistema de Pontuação (Score): Calculado com base em erros e tempo
                score_final = pontuacao_maxima - ((tentativas_gastas - 1) * 100);
                if (modo == 2) score_final *= 2; 
                if (modo == 3) score_final += ((tempo_limite - tempo_passado) * 20);
                if (score_final < 100) score_final = 100; 

                printf("%s\n🎉 ACERTOU! O número era %d em %d tentativas!\n", C_GREEN, numero_secreto, tentativas_gastas);
                printf("🏆 SCORE: %d PONTOS!%s\n", score_final, C_RESET);
                
                // [H15] Efeitos Sonoros: Som de vitória acionado
                som_vitoria();
            } 
            else {
                // [H4] Dicas Visuais: Muito alto ou Muito baixo
                if (palpite > numero_secreto) printf("%s🔼 Muito Alto!%s\n", C_YELLOW, C_RESET);
                else printf("%s🔽 Muito Baixo!%s\n", C_YELLOW, C_RESET);
                
                if (modo == 2) printf("%sTentativas restantes: %d%s\n", C_RED, limite_tentativas - tentativas_gastas, C_RESET);
                if (modo == 3) { 
                    printf("%s⏱️ Tempo restante: %d seg%s\n", C_YELLOW, tempo_limite - tempo_passado, C_RESET); 
                    som_alerta(); // [H15] Bip de alerta
                }
            }
        }
        
        if (!acertou) {
            if (tempo_esgotado) printf("%s\n⏱️ GAME OVER! O tempo acabou! Era %d.%s\n", C_RED, numero_secreto, C_RESET);
            else printf("%s\n💀 GAME OVER! Tentativas esgotadas. Era %d.%s\n", C_RED, numero_secreto, C_RESET);
            
            // [H15] Efeitos Sonoros: Som de derrota acionado
            som_derrota();
        }
        
        // [H6] Persistência em Arquivo .txt & [H21] Mascaramento de Segurança
        FILE *arquivo = fopen("historico_partidas.txt", "a");
        if (arquivo != NULL) {
            // [H21] Soma +17 aos dados reais para ofuscar (mascarar) a gravação no TXT
            fprintf(arquivo, "%d %d %d\n", numero_secreto + 17, tentativas_gastas + 17, score_final + 17);
            fclose(arquivo);
        }
        
        // Final do bloco [H13] Loop de Rejogabilidade
        printf("\nJogar novamente? (S/N): ");
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, " %c", &jogar_novamente);
        
    } while (jogar_novamente == 'S' || jogar_novamente == 's');
    
    printf("%s\nOBRIGADO POR JOGAR!%s\n\n", C_CYAN, C_RESET);
    return 0;
}

// Fim 
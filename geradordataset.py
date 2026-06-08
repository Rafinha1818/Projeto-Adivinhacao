import random


# [H7] Script de Python para uma geração automática de dataset de teste (150 partidas)
# [H21] Atualizado com a Camada de Mascaramento para compatibilidade com o Jogo em C

quantidade_partidas = 150
nome_arquivo = "historico_partidas.txt"
chave_mascara = 17 # A mesma chave secreta usada no jogo.c e analise_recursiva.c

print("A iniciar a geração do dataset de testes...")

with open(nome_arquivo, "w") as arquivo:
    for i in range(quantidade_partidas):
        # Gera dados fictícios realistas (ex: números de 1 a 100, tentativas de 1 a 15)
        numero_secreto = random.randint(1, 100)
        tentativas = random.randint(1, 15)
        score = random.randint(100, 1000)
        
        # [H21] Aplica a máscara matemática (ofuscação) antes de gravar
        numero_mascarado = numero_secreto + chave_mascara
        tentativas_mascaradas = tentativas + chave_mascara
        score_mascarado = score + chave_mascara

        # Grava no ficheiro de texto
        arquivo.write(f"{numero_mascarado} {tentativas_mascaradas} {score_mascarado}\n")

print(f"✅ Sucesso! Dataset com {quantidade_partidas} partidas gerado no ficheiro '{nome_arquivo}'.")
print(f"🔒 Os dados foram ofuscados com a chave de segurança (+{chave_mascara}).")

# Fim
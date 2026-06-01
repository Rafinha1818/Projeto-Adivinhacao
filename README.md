# 🎲 Jogo de Adivinhação Inteligente (em C)

Olá! 👋 Este é um projeto de programação onde peguei o jogo de adivinhar o número e adicionei um sistema de análise de dados por trás dele. 

A ideia aqui não é apenas jogar, mas praticar **ficheiros (I/O)** e comparar **paradigmas de programação** (usando laços normais vs. funções recursivas), tudo isto seguindo **metodologias ágeis (Scrum/Kanban)**.

## 👤 Papéis e Responsabilidades
Este projeto foi desenvolvido **individualmente** por mim. Para manter a organização e simular um fluxo de trabalho profissional, assumi as seguintes responsabilidades ao longo do desenvolvimento:

* **[Rafael de Andrade Arruda]**: 
  * **Product Owner (PO)**: Definição do backlog do produto e redação das Histórias de Utilizador.
  * **Scrum Master**: Organização do quadro Kanban e priorização das entregas.
  * **Desenvolvedor Principal (C & Python)**: Implementação do Jogo Interativo (Paradigma Imperativo), do Analisador Estatístico (Paradigma Recursivo) e do Script Gerador de Dados.

## 🛠️ Metodologia e Histórias de Utilizador
O desenvolvimento seguiu o framework Ágil com base em 13 Histórias de Utilizador bem definidas no padrão **3Cs (Cartão, Conversa, Confirmação)**.

### 📝 Backlog Priorizado ( Com suas prioridades e status atuais )

H1	Interface de boas-vindas e explicação das regras.	Alta	✅

H2	Geração aleatória do número secreto pelo sistema.	Alta	✅

H3	Entrada de palpites do usuário via terminal.	Alta	✅

H4	Dicas visuais ("Muito alto" ou "Muito baixo") após cada erro.	Alta	✅

H5	Contador de tentativas para medir performance da partida.	Média	✅

H6	Persistência: Gravação do resultado da partida em arquivo .txt.	Alta	✅

H7	Script Python para geração automática de dataset de teste (150 partidas).	Média	✅

H8	Leitura e carregamento do arquivo de histórico pelo programa C.	Alta	✅

H9	Cálculo de Média e Desvio Padrão usando Recursividade.	Alta	✅

H10	Sistema de Insight: Sugestão de estratégia baseada na média do jogador.	Baixa	✅

H11	Níveis de Dificuldade: Seleção de intervalos (1-50, 1-100, 1-500).	Média	✅

H12	Modo Morte Súbita: Opção de limite rígido de 7 tentativas.	Média	✅

H13	Loop de Rejogabilidade: Reiniciar o jogo sem encerrar o executável.	Alta	✅

---

# Épico 1 - Desenvolvimento de Jogo de Advinhação Análitico

> "Como jogador e estudante, eu quero um jogo de adivinhação via terminal que não apenas funcione com mecânicas de dicas, mas que também registre todas as minhas partidas em um arquivo de texto para calcular, de forma recursiva, estatísticas do meu desempenho e me sugerir melhores estratégias."

---

## 📂 Ficheiros do Projeto
* 🐍 **`geradordataset.py`**: Script em Python que cria os dados mockados
* 🎮 **`jogo.c`**: O jogo em si (Paradigma Imperativo)
* 📊 **`analise_recursiva.c`**: O cérebro da operação (Paradigma Funcional/Recursivo)

---


# Como rodar o projeto ( Terminal )

 - Compilar o Jogo
gcc jogo.c -o jogo.exe

 - Compilar a Análise (necessário -lm para math.h)
gcc analise_recursiva.c -o analise.exe -lm

 - Executar
.\jogo.exe

---
## Quadro Kanban, Histórias de Usuário e Protótipo

# Trello (Kanban) + Histórias de Usuário:
https://trello.com/b/T2SYFo8U/projeto-advinhacao

<img width="1142" height="503" alt="image" src="https://github.com/user-attachments/assets/dc5302a6-7fed-4f17-9497-6064ecb34112" />


---

# Protótipo:
https://www.figma.com/make/4IkJ2TC3GcWov95XMemC4y/Prot%C3%B3tipo-Jogo-Advinha%C3%A7%C3%A3o?fullscreen=1&t=A08Xi9uWNA31xWDQ-1

<img width="1288" height="534" alt="image" src="https://github.com/user-attachments/assets/bcb8014d-82a4-46a8-8362-65dae4e7dd0a" />


---
# Relato de programação em Par

- O projeto foi desenvolvido de forma individual, aplicando técnicas de revisão de código contínua para garantir a qualidade das funções recursivas e da integração com o dataset. Porém com o auxilio em umas partes do código com uma IA ( Principalmente em ajustes )

---

# Issue/Bug Tracker

- Até o momento, houveram 4 bugs solucionados.

<img width="1278" height="342" alt="image" src="https://github.com/user-attachments/assets/61693833-0c31-4d1a-8cf1-4651a7b020f9" />

---

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
O desenvolvimento seguiu o framework Ágil com base em 10 Histórias de Utilizador bem definidas no padrão **3Cs (Cartão, Conversa, Confirmação)**.

### 📝 Backlog Priorizado

**#1 - Estrutura Base do Jogo (Prioridade Alta)**
> **Como** jogador, **quero** que o programa inicie o jogo e me dê as boas-vindas com instruções claras, **para que** eu entenda rapidamente o que devo fazer.
> *Critérios de Aceitação:* O programa corre no terminal, exibe a mensagem de "Bem-vindo" e instrui o palpite de 1 a 100.

**#2 - Geração de Número Aleatório (Prioridade Alta)**
> **Como** jogador, **quero** que o jogo escolha um número secreto diferente a cada nova partida, **para que** a experiência não seja repetitiva.
> *Critérios de Aceitação:* Usa a semente do relógio (`srand`) para garantir um número único.

**#3 - Ciclo de Palpites (Prioridade Alta)**
> **Como** jogador, **quero** poder digitar vários palpites consecutivos, **para que** eu possa continuar a tentar até acertar no número secreto.
> *Critérios de Aceitação:* O jogo usa um laço de repetição contínuo até ao acerto.

**#4 - Dicas de Maior/Menor (Prioridade Alta)**
> **Como** jogador, **quero** receber um aviso a dizer se o meu palpite foi "muito alto" ou "muito baixo", **para que** eu possa criar uma estratégia.
> *Critérios de Aceitação:* Compara o palpite com o alvo e exibe as dicas a cada erro.

**#5 - Registo de Tentativas da Sessão (Prioridade Média)**
> **Como** analista de dados, **quero** que o jogo conte as tentativas e guarde o histórico de palpites do jogador na memória, **para que** esses dados possam ser exportados depois.
> *Critérios de Aceitação:* Variável contador incrementada e palpites guardados num array.

**#6 - Guardar Partida em Ficheiro (Prioridade Média)**
> **Como** jogador, **quero** que o histórico das minhas partidas concluídas seja guardado automaticamente no meu computador, **para que** eu não perca o meu progresso.
> *Critérios de Aceitação:* O jogo abre um ficheiro `.txt` no modo *append* e grava ID, Alvo, Total de Tentativas e palpites.

**#7 - Gerador de Dataset Simulado (Prioridade Média)**
> **Como** desenvolvedor, **quero** correr um script que crie rapidamente 150 partidas falsas, **para que** eu possa testar as ferramentas de análise sem jogar manualmente.
> *Critérios de Aceitação:* Script Python que gera `historico_partidas.txt` simulando estratégias boas e ruins.

**#8 - Leitura do Ficheiro de Histórico (Prioridade Baixa)**
> **Como** estudante de estatística, **quero** que a ferramenta consiga ler todas as partidas guardadas no documento de texto, **para que** eu tenha acesso aos dados brutos.
> *Critérios de Aceitação:* Abre o ficheiro no modo leitura (`"r"`) e recolhe os dados formatados.

**#9 - Cálculos Estatísticos Recursivos (Prioridade Baixa)**
> **Como** professor de programação, **quero** que os cálculos de média e desvio padrão sejam feitos exclusivamente via recursão, **para que** sirva como caso de estudo deste paradigma.
> *Critérios de Aceitação:* Funções matemáticas criadas sem o uso de `for` ou `while`.

**#10 - Geração de Sugestão de Estratégia (Prioridade Baixa)**
> **Como** jogador em busca de melhoria, **quero** receber feedback baseado na minha média geral, **para que** eu descubra se preciso de mudar a minha tática.
> *Critérios de Aceitação:* Compara a média com o limite da Busca Binária (7) e exibe uma dica.
> 
---

## 📂 Ficheiros do Projeto
* 🐍 **`geradordataset.py`**: Script em Python que cria os dados mockados
* 🎮 **`jogo.c`**: O jogo em si (Paradigma Imperativo)
* 📊 **`analise_recursiva.c`**: O cérebro da operação (Paradigma Funcional/Recursivo)

## 🚀 Como testar no computador

Apenas é necessário ter o Python e o compilador GCC instalados.

**1. Criar os dados de teste:**

   python geradordataset.py

**2. Jogar uma partida:**

   gcc jogo.c -o jogo.exe
   .\jogo.exe

**3. Ver as estatísticas e os insights:**

  gcc analise_recursiva.c -o analise.exe
  .\analise.exe

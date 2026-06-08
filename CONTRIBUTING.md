# 🤝 Como Contribuir para o Retro Arcade System

Obrigado pelo interesse em contribuir para o nosso jogo de adivinhação! Este documento serve como um guia rápido para configurar o ambiente de desenvolvimento na sua máquina e submeter as suas melhorias.

## 🛠️ Configuração do Ambiente (Setup Local)

Para rodar o projeto localmente, precisará das seguintes ferramentas:
* **Git** (para clonar o repositório)
* **Compilador C** (Recomendo o GCC - MinGW no Windows ou nativo no Linux/macOS)

### Passos para Instalação:
1. Clone este repositório para a sua máquina:
   git clone https://github.com/Rafinha1818/Projeto-Adivinhacao.git

2. Navegue até à pasta do projeto:
   cd https://github.com/Rafinha1818/Projeto-Adivinhacao.git

3. Compile o jogo principal utilizando o GCC:
   gcc jogo.c -o jogo.exe

4. Compile o módulo de análise estatística:
   gcc analise_recursiva.c -o analise.exe

5. Execute o jogo (O ficheiro de base de dados .txt será gerado automaticamente na primeira partida):
   .\jogo.exe




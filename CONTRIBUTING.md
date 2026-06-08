# 🤝 Como Contribuir para o Jogo de Advinhação Otimizado

Obrigado pelo interesse em contribuir para o meu jogo de adivinhação! Este documento serve como um guia rápido para configurar o ambiente de desenvolvimento na sua máquina e submeter as suas melhorias.

## 🛠️ Configuração do Ambiente (Setup Local)

Para rodar o projeto localmente, precisará das seguintes ferramentas:
* **Git** (para clonar o repositório)
* **Compilador C** (Recomendo o GCC - MinGW no Windows ou nativo no Linux/macOS)

### Passos para Instalação:
1. Clone este repositório para a sua máquina:
   git clone https://github.com/Rafinha1818/Projeto-Adivinhacao.git

2. Navegue até à pasta do projeto:
   cd Projeto-Adivinhacao

3. Compile o jogo principal utilizando o GCC:
   gcc jogo.c -o jogo.exe

4. Compile o módulo de análise estatística:
   gcc analise_recursiva.c -o analise.exe

5. Execute o jogo (O ficheiro de base de dados .txt será gerado automaticamente na primeira partida):
   .\jogo.exe


## 🚀 Como Contribuir com Código

1. Crie uma nova branch para a sua funcionalidade:
   git checkout -b feature/minha-nova-funcionalidade

2. Faça as suas alterações no código fonte. Certifique-se de que o código compila sem erros (warnings).

3. Adicione os ficheiros modificados:
   git add .

4. Faça o commit utilizando o padrão de Conventional Commits:

feat: para novas funcionalidades

fix: para correção de bugs

docs: para alterações na documentação

Exemplo: git commit -m "feat: adiciona novo tema de cores neon"

5. Envie a sua branch para o repositório remoto:
   git push origin feature/minha-nova-funcionalidade

6. Abra um Pull Request no GitHub detalhando as alterações propostas.

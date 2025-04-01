# Jogo da Forca em C

Este projeto é uma implementação simples do jogo da forca utilizando a linguagem C. O jogo escolhe aleatoriamente uma palavra e o jogador deve adivinhar as letras antes de esgotar suas tentativas.

## 📌 Funcionalidades
- Escolha aleatória de palavras.
- Representação gráfica da forca no terminal.
- Sistema de tentativas limitadas.
- Revelação progressiva da palavra conforme o jogador acerta as letras.
- Verificação automática de vitória.

## 📜 Como funciona
1. O jogo seleciona uma palavra aleatoriamente de uma lista pré-definida.
2. A palavra é ocultada com "_".
3. O jogador deve adivinhar as letras, digitando uma por vez.
4. Se a letra estiver na palavra, ela será revelada.
5. Se a letra não estiver na palavra, o número de tentativas restantes diminui.
6. O jogo termina quando:
   - O jogador adivinha todas as letras corretamente (vitória).
   - O jogador esgota suas tentativas (derrota).

## 🛠 Estrutura do Código

### Funções principais

#### `void escolha_palavras()`
Escolhe uma palavra aleatória de um conjunto pré-definido.

#### `void imprimir_forca(int tentativas_restantes)`
Desenha a forca no terminal de acordo com o número de tentativas restantes.

#### `void camufla_palavra(const char *palavra, char *palavra_oculta, int tamanho_palavra)`
Oculta a palavra com "_" para iniciar o jogo.

#### `void revela_letra(const char *palavra, char *palavra_oculta, char letra)`
Revela uma letra caso o jogador acerte.

#### `int verifica_vitoria(const char *palavra_oculta)`
Verifica se todas as letras foram reveladas e retorna 1 para vitória ou 0 caso contrário.

### `int main()`
Função principal que inicia o jogo, gerencia as interações com o jogador e controla o fluxo do jogo.

## 📥 Como executar o código

1. Clone este repositório:
   ```sh
   git clone https://github.com/seu-usuario/jogo-da-forca-c.git
   ```
2. Compile o código com um compilador C, como `gcc`:
   ```sh
   gcc jogo_da_forca.c -o forca
   ```
3. Execute o jogo:
   ```sh
   ./forca
   ```

## 🎯 Melhorias Futuras
- Adicionar suporte para palavras com acentos.
- Criar uma interface gráfica.
- Implementar um sistema de pontuação.
- Permitir diferentes categorias de palavras.

---

🚀 **Divirta-se jogando a forca!** Se gostou, deixe uma ⭐ no repositório!


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const char *escolha_palavras() {
    const char *palavras[] = {
        "PARALELO", "ESCOLA", "XICARA DE XA", "CAVALO SELVAGEM", "CEU ESTRELADO",
        "PIANO PRETO", "FLORESTA ENCANTADA", "CASA ANTIGA", "PORTA FECHADA",
        "TELEFONE SEM FIO", "MONTANHA RUSSA", "CARRO VELOZ", "LIVRO NOVO",
        "LAPIS QUEBRADO", "GATO MANHOSO", "CAFE AMARGO", "CHUVA TORRENCIAL",
        "LUA CRESCENTE", "RIO SINUOSO", "JANELA ABERTA", "CANCAO TRISTE",
        "DANCA ENERGETICA", "PINTURA ABSTRATA", "CACHORRO DORMINHOCO", "CAMPANHA ELEITORAL",
        "PALAVRA CRUZADA", "PONTE DE PEDRA", "COMPUTADOR ANTIGO", "LARANJA MADURA",
        "BOLA QUICANDO", "VENTO SUAVE", "FOGO ARDENTE", "VERAO ESCALDANTE", "INVERNO RIGOROSO",
        "PRIMAVERA FLORESCENTE", "OUTONO DOURADO", "TERRA FERTIL", "MAR CALMO",
        "ESTRELA CADENTE", "NEVE BRANCA", "BRINQUEDO QUEBRADO", "ESPERANCA RENOVADA",
        "SONHO DISTANTE", "CRIANCA SORRIDENTE", "HORIZONTE DISTANTE", "AMOR VERDADEIRO",
        "SAUDADE APERTADA", "TEMPESTADE VIOLENTA", "AVENTURA SEM FIM", "HISTORIA INESQUECIVEL"
    };

    int num_palavras = sizeof(palavras) / sizeof(palavras[0]);
    int indice = rand() % num_palavras;
    return palavras[indice];
}

void imprimir_forca(int tentativas_restantes) {
    printf("Tentativas restantes: %d\n", tentativas_restantes);
    printf("  _______\n");
    printf(" |       |\n");
    printf(" |       %s\n", (tentativas_restantes < 6) ? "O" : " ");
    printf(" |      %s%s%s\n", (tentativas_restantes < 5) ? "/" : " ", (tentativas_restantes < 4) ? "|" : " ", (tentativas_restantes < 3) ? "\\" : " ");
    printf(" |      %s %s\n", (tentativas_restantes < 2) ? "/" : " ", (tentativas_restantes < 1) ? "\\" : " ");
    printf(" |\n");
    printf("_|_\n");
}

void camufla_palavra(const char *palavra, char *palavra_oculta) {
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho; i++) {
        palavra_oculta[i] = (palavra[i] == ' ') ? ' ' : '_';
    }
    palavra_oculta[tamanho] = '\0';
}

void revela_letra(const char *palavra, char *palavra_oculta, char letra) {
    for (int i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] == letra) {
            palavra_oculta[i] = letra;
        }
    }
}

int verifica_vitoria(const char *palavra_oculta) {
    return strchr(palavra_oculta, '_') == NULL;
}

int main() {
    srand(time(NULL));
    
    const char *palavra = escolha_palavras();
    int tamanho = strlen(palavra);
    char palavra_oculta[tamanho + 1];
    camufla_palavra(palavra, palavra_oculta);

    int tentativas_restantes = 6;
    char letra;

    while (tentativas_restantes > 0) {
        imprimir_forca(tentativas_restantes);
        printf("Palavra: %s\n", palavra_oculta);
        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        if (strchr(palavra, letra)) {
            revela_letra(palavra, palavra_oculta, letra);
        } else {
            tentativas_restantes--;
        }

        if (verifica_vitoria(palavra_oculta)) {
            printf("Parabéns! Você adivinhou a palavra: %s\n", palavra);
            break;
        }
    }

    if (tentativas_restantes == 0) {
        imprimir_forca(tentativas_restantes);
        printf("Você perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
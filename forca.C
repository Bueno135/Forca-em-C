#include <stdio.h>
#include <stdlib.h>

void escolha_palavras(){

    const char *palavras[] = 
    {"PARALELO", "ESCOLA", "XICARA DE XA", "CAVALO SELVAGEM", "CEU ESTRELADO",
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
    const char *palavra_escolhida = palavras[indice]; 

}

void imprimir_forca(int tentativas_restantes){

    printf("Tentativas restantes: %d\n", tentativas_restantes);
    printf("  _______\n");
    printf(" |       |\n");
    printf(" |       %s\n", (tentativas_restantes < 6) ? "O" : " ");
    printf(" |      %s%s%s\n", (tentativas_restantes < 5) ? "/" : " ", (tentativas_restantes < 4) ? "|" : " ", (tentativas_restantes < 3) ? "\\" : " ");
    printf(" |      %s %s\n", (tentativas_restantes < 2) ? "/" : " ", (tentativas_restantes < 1) ? "\\" : " ");
    printf(" |\n");
    printf("_|_\n");
}
void camufla_palavra(const char *palavra, char *palavra_oculta, int tamanho_palavra){

    for(int i = 0; i < tamanho_palavra; i++){
        palavra_oculta[i] = '_';
    }
    palavra_oculta[tamanho_palavra] = '\0'; // Adiciona o terminador nulo
}
void revela_letra(const char *palavra, char *palavra_oculta, char letra){

    for(int i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] == letra){
            palavra_oculta[i] = letra;
        }
    }
}
int verifica_vitoria(const char *palavra_oculta){

    for(int i = 0; palavra_oculta[i] != '\0'; i++){
        if(palavra_oculta[i] == '_'){
            return 0; // A palavra ainda não foi totalmente revelada
        }
    }
    return 1; // A palavra foi totalmente revelada
}


int main(){

    



    return 0;
}
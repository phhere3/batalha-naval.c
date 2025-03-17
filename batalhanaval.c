#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int orientacao) {
    if (orientacao == 0) { // Horizontal
        if (coluna + NAVIO > TAMANHO) return 0; // Fora dos limites
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) return 0; // Sobreposição
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    } else { // Vertical
        if (linha + NAVIO > TAMANHO) return 0;
        for (int i = 0; i < NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
        for (int i = 0; i < NAVIO; i++) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
    return 1;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializarTabuleiro(tabuleiro);

    // Definição das coordenadas dos navios
    int linha1 = 2, coluna1 = 3; // Posição inicial do navio horizontal
    int linha2 = 5, coluna2 = 6; // Posição inicial do navio vertical

    // Posiciona os navios no tabuleiro
    if (!posicionarNavio(tabuleiro, linha1, coluna1, 0)) {
        printf("Erro ao posicionar o navio horizontal.\n");
    }
    if (!posicionarNavio(tabuleiro, linha2, coluna2, 1)) {
        printf("Erro ao posicionar o navio vertical.\n");
    }

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}

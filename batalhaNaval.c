#include <stdio.h>


int main() {
    
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    int linhaH = 3, colunaH = 4;
    int linhaV = 7, colunaV = 7;

    int tabuleiro[10][10] = {0}; // Inicializa tudo com 0

    // Posiciona navio horizontal
    for(int i = 0; i < 3; i++){
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical
    for(int i = 0; i < 3; i++){
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // Imprime o tabuleiro
    for (int linha = 0; linha < 10; linha++) {
        for (int coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}

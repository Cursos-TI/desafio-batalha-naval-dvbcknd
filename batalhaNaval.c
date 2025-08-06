#include <stdio.h>
#include <stdbool.h>

#define TAM 10       // Tamanho do tabuleiro
#define NAVIO 3      // Valor que representa parte do navio
#define TAMANHO 3    // Tamanho fixo dos navios

// Função para verificar se uma posição está livre
bool posicaoValida(int tabuleiro[TAM][TAM], int linha, int coluna) {
    return (tabuleiro[linha][coluna] == 0);
}

// Função para posicionar navio horizontal
bool posicionarHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + TAMANHO > TAM) return false; // Fora do limite
    for (int i = 0; i < TAMANHO; i++) {
        if (!posicaoValida(tabuleiro, linha, coluna + i)) return false;
    }
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[linha][coluna + i] = NAVIO;
    }
    return true;
}

// Função para posicionar navio vertical
bool posicionarVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAMANHO > TAM) return false; // Fora do limite
    for (int i = 0; i < TAMANHO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna)) return false;
    }
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[linha + i][coluna] = NAVIO;
    }
    return true;
}

// Função para posicionar navio diagonal (crescente)
bool posicionarDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAMANHO > TAM || coluna + TAMANHO > TAM) return false;
    for (int i = 0; i < TAMANHO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna + i)) return false;
    }
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[linha + i][coluna + i] = NAVIO;
    }
    return true;
}

// Função para posicionar navio diagonal (decrescente)
bool posicionarDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + TAMANHO > TAM || coluna - (TAMANHO - 1) < 0) return false;
    for (int i = 0; i < TAMANHO; i++) {
        if (!posicaoValida(tabuleiro, linha + i, coluna - i)) return false;
    }
    for (int i = 0; i < TAMANHO; i++) {
        tabuleiro[linha + i][coluna - i] = NAVIO;
    }
    return true;
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro:\n");
    for (int linha = 0; linha < TAM; linha++) {
        for (int coluna = 0; coluna < TAM; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa com 0 (água)

    // Posicionando os 4 navios conforme os requisitos
    if (!posicionarHorizontal(tabuleiro, 3, 4))
        printf("Falha ao posicionar navio horizontal.\n");
    if (!posicionarVertical(tabuleiro, 0, 0))
        printf("Falha ao posicionar navio vertical.\n");
    if (!posicionarDiagonalPrincipal(tabuleiro, 5, 2))
        printf("Falha ao posicionar navio diagonal principal.\n");
    if (!posicionarDiagonalSecundaria(tabuleiro, 1, 9))
        printf("Falha ao posicionar navio diagonal secundaria.\n");

    // Exibe o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}

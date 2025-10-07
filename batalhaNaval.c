#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    // Inicializa todas as posições com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho dos navios
    int tamanho_navio = 3;

    // Coordenadas iniciais dos navios (garantindo que não se sobreponham)
    int linha_h = 1, coluna_h = 2; // navio horizontal começa em (1,2)
    int linha_v = 5, coluna_v = 7; // navio vertical começa em (5,7)
    int linha_diag1 = 0, coluna_diag1 = 0; // navio diagonal principal começa em (0,0)
    int linha_diag2 = 7, coluna_diag2 = 2; // navio diagonal secundária começa em (7,2)

    // Posiciona navio horizontal (horizontal para direita)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_h][coluna_h + i] = 3;
    }
    // Posiciona navio vertical (vertical para baixo)
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_v + i][coluna_v] = 3;
    }
    // Posiciona navio diagonal principal (de cima para baixo, esquerda para direita)
    int sobreposicao = 0;
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_diag1 + i][coluna_diag1 + i] != 0) sobreposicao = 1;
    }
    if (!sobreposicao) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_diag1 + i][coluna_diag1 + i] = 3;
        }
    }
    // Posiciona navio diagonal secundária (de baixo para cima, esquerda para direita)
    sobreposicao = 0;
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_diag2 - i][coluna_diag2 + i] != 0) sobreposicao = 1;
    }
    if (!sobreposicao) {
        for (int i = 0; i < tamanho_navio; i++) {
            tabuleiro[linha_diag2 - i][coluna_diag2 + i] = 3;
        }
    }
    // Exibe o tabuleiro com navios posicionados
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    // Cabeçalho das colunas
    printf("   ");
    for (int j = 0; j < 10; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    printf("   -----------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("%2d|", i);
        for (int j = 0; j < 10; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    return 0;
}

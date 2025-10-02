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
    // Vetores para os navios
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios (garantindo que não se sobreponham)
    int linha_h = 1, coluna_h = 2; // navio horizontal começa em (1,2)
    int linha_v = 5, coluna_v = 7; // navio vertical começa em (5,7)

    // Posiciona navio horizontal
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_h][coluna_h + i] = navio_horizontal[i];
    }
    // Posiciona navio vertical
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_v + i][coluna_v] = navio_vertical[i];
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

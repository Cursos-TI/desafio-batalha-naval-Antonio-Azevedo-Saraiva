// Função para sobrepor e marcar cada habilidade individualmente
void sobrepor_marca(int efeito[10][10], int habilidade[5][5], int origem_l, int origem_c) {
    int offset = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int l = origem_l + (i - offset);
            int c = origem_c + (j - offset);
            if (l >= 0 && l < 10 && c >= 0 && c < 10) {
                if (habilidade[i][j] == 1) {
                    efeito[l][c] = 1;
                }
            }
        }
    }
}

#include <stdio.h>

// Função para sobrepor matriz de habilidade ao tabuleiro
void sobrepor_habilidade(int tab[10][10], int habilidade[5][5], int origem_l, int origem_c) {
    int offset = 2; // centro da matriz 5x5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int l = origem_l + (i - offset);
            int c = origem_c + (j - offset);
            if (l >= 0 && l < 10 && c >= 0 && c < 10) {
                if (habilidade[i][j] == 1 && tab[l][c] == 0) {
                    tab[l][c] = 5; // 5 representa área de efeito
                }
            }
        }
    }
}

int main() {
    // Matrizes de habilidades (5x5)
    // Cone: triângulo para baixo
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    // Cruz: linhas e colunas centrais
    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };
    // Octaedro: losango centralizado
    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0}
    };

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

    // Cópia do tabuleiro para exibir áreas de efeito
    int tabuleiro_habilidade[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro_habilidade[i][j] = tabuleiro[i][j];
        }
    }

    // Pontos de origem das habilidades
    int origem_cone_l = 2, origem_cone_c = 2;
    int origem_cruz_l = 5, origem_cruz_c = 5;
    int origem_octaedro_l = 7, origem_octaedro_c = 7;

    // Matrizes auxiliares para marcar cada habilidade separadamente
    int efeito_cone[10][10] = {0};
    int efeito_cruz[10][10] = {0};
    int efeito_octaedro[10][10] = {0};


    sobrepor_marca(efeito_cone, cone, origem_cone_l, origem_cone_c);
    sobrepor_marca(efeito_cruz, cruz, origem_cruz_l, origem_cruz_c);
    sobrepor_marca(efeito_octaedro, octaedro, origem_octaedro_l, origem_octaedro_c);
    // Exibe o tabuleiro com áreas de efeito
    printf("Tabuleiro Batalha Naval:\nC = Cone, X = Cruz, O = Octaedro, N = Navio, ~ = Água\n\n");
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
            if (tabuleiro[i][j] == 3) {
                printf(" N "); // Navio
            } else if (efeito_cone[i][j]) {
                printf(" C "); // Cone
            } else if (efeito_cruz[i][j]) {
                printf(" X "); // Cruz
            } else if (efeito_octaedro[i][j]) {
                printf(" O "); // Octaedro
            } else {
                printf(" ~ "); // Água
            }
        }
        printf("\n");
    }
    return 0;
}

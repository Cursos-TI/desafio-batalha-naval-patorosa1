#include <stdio.h>

// Tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração da matriz 10x10 e inicialização com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios (linha, coluna)
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 4;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 1;

    int podeColocar = 1;

    // Verifica se o navio horizontal cabe no tabuleiro
    // Verifica sobreposição do navio horizontal
    if (colunaNavioHorizontal + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] != 0) {
                podeColocar = 0;
                break;
            }
        }
        // Posiciona o navio horizontal se possível
        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3;
            }
        } else {
            printf("Erro: Sobreposição ao posicionar o navio horizontal!\n");
            return 1;
        }
    } else {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    podeColocar = 1;

    // Verifica se o navio vertical cabe no tabuleiro
    // Verifica sobreposição do navio vertical
    if (linhaNavioVertical + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaNavioVertical + i][colunaNavioVertical] != 0) {
                podeColocar = 0;
                break;
            }
        }
        // Posiciona o navio vertical se possível
        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
            }
        } else {
            printf("Erro: Sobreposição ao posicionar o navio vertical!\n");
            return 1;
        }
    } else {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // Mostra o tabuleiro com 0 (água) e 3 (navios)
    printf("\n--- Tabuleiro Batalha Naval ---\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}


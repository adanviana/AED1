#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz() {
    int** matriz = malloc(9 * sizeof(int*));
    for (int i = 0; i < 9; i++) {
        matriz[i] = malloc(9 * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(int** matriz) {
    for (int i = 0; i < 9; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void lerMatriz(int** sudoku) {
    for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
}

int linhaValida(int** sudoku, int linha) {
    int verificador[10] = {0};
    for (int coluna = 0; coluna < 9; coluna++) {
        int num = sudoku[linha][coluna];
    if (num < 1 || num > 9 || verificador[num] == 1) {
            return 0;
        }
        verificador[num] = 1;
    }
    return 1;
}

int colunaValida(int** sudoku, int coluna) {
    int verificador[10] = {0};
    for (int linha = 0; linha < 9; linha++) {
        int num = sudoku[linha][coluna];
    if (num < 1 || num > 9 || verificador[num] == 1) {
            return 0;
        }
        verificador[num] = 1;
    }
    return 1;
}

int regiaoValida(int** sudoku, int regiaoLinha, int regiaoColuna) {
    int verificador[10] = {0};
    int linhaInicio = regiaoLinha * 3;
    int colunaInicio = regiaoColuna * 3;
    for (int i = linhaInicio; i < linhaInicio + 3; i++) {
    for (int j = colunaInicio; j < colunaInicio + 3; j++) {
            int num = sudoku[i][j];
            if (num < 1 || num > 9 || verificador[num] == 1) {
                return 0;
            }
            verificador[num] = 1;
        }
    }
    return 1;
}

int sudokuValido(int** sudoku) {
    for (int i = 0; i < 9; i++) {
    if (!linhaValida(sudoku, i) || !colunaValida(sudoku, i)) {
            return 0;
        }
    }
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
            if (!regiaoValida(sudoku, i, j)) {
            return 0;
            }
        }
    }
    return 1;
}

int main() {
    int** sudoku = alocarMatriz();
    lerMatriz(sudoku);
    
    if (sudokuValido(sudoku)) {
        printf("Solucao valida\n");
    } else {
        printf("Solucao invalida\n");
    }
    
    liberarMatriz(sudoku);
    return 0;
}
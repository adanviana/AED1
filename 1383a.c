#include <stdio.h>

int linhaValida(int sudoku[9][9], int linha) {
    int verificador[10] = {0}; 
    
    for (int coluna = 0; coluna < 9; coluna++) {
        int num = sudoku[linha][coluna];
        if (num < 1 || num > 9) {
            return 0;
        }
        
        if (verificador[num] == 1) {
            return 0;
        }
        
        verificador[num] = 1;
    }
    
    return 1;
}

int colunaValida(int sudoku[9][9], int coluna) {
    int verificador[10] = {0};
    
    for (int linha = 0; linha < 9; linha++) {
        int num = sudoku[linha][coluna];
        if (num < 1 || num > 9) {
            return 0;
        }
        
        if (verificador[num] == 1) {
            return 0;
        }
        
        verificador[num] = 1;
    }
    
    return 1;
}


int regiaoValida(int sudoku[9][9], int regiaoLinha, int regiaoColuna) {
    int verificador[10] = {0};
    
    int linhaInicio = regiaoLinha * 3;
    int colunaInicio = regiaoColuna * 3;
    
    for (int i = linhaInicio; i < linhaInicio + 3; i++) {
        for (int j = colunaInicio; j < colunaInicio + 3; j++) {
            int num = sudoku[i][j];
            if (num < 1 || num > 9) {
                return 0;
            }
            
            if (verificador[num] == 1) {
                return 0;
            }
            
            verificador[num] = 1;
        }
    }
    
    return 1;
}

int sudokuValido(int sudoku[9][9]) {
    for (int linha = 0; linha < 9; linha++) {
        if (!linhaValida(sudoku, linha)) {
            return 0;
        }
    }
    


    for (int coluna = 0; coluna < 9; coluna++) {
        if (!colunaValida(sudoku, coluna)) {
            return 0;
        }
    }
    
    for (int regiaoLinha = 0; regiaoLinha < 3; regiaoLinha++) {
        for (int regiaoColuna = 0; regiaoColuna < 3; regiaoColuna++) {
            if (!regiaoValida(sudoku, regiaoLinha, regiaoColuna)) {
                return 0;
            }
        }
    }
    
    return 1;
}

int main() {
    int sudoku[9][9];
    
    printf("Digite a matriz 9x9:\n");
    printf("(Digite os números separados por espaço)\n\n");
    
    for (int i = 0; i < 9; i++) {
        printf("Linha %d: ", i + 1);
        for (int j = 0; j < 9; j++) {
            scanf("%d", &sudoku[i][j]);
        }
    }
    
    printf("\nMatriz informada:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    
    if (sudokuValido(sudoku)) {
        printf("\nSIM - A matriz e uma solucao valida\n");
    } else {
        printf("\nNAO - A matriz nao e uma solucao valida\n");
    }
    
    return 0;
}
#include <stdlib.h>
#include <stdio.h>


int main() {
    int N;
    scanf("%d", &N);
    
    int *X = malloc(N * sizeof(int));
    if (!X) return 1;
    
    for (int *p = X; p < X + N; p++) {
        scanf("%d", p);
    }
    
    int menor = *X, posicao = 0;
    for (int i = 1; i < N; i++) {
        if (X[i] < menor) {
            menor = X[i];
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
    
    free(X);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *X = (int*)malloc(N * sizeof(int));
    
    int *ptr = X;
    for (int i = 0; i < N; i++) {
        scanf("%d", ptr);
        ptr++;
    }
    
    int menor = *X; 
    int posicao = 0;
    
    ptr = X + 1; 
    for (int i = 1; i < N; i++) {
        if (*ptr < menor) {
            menor = *ptr;
            posicao = i;
        }
        ptr++;
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    free(X);
    return 0;
}
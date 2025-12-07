#include <stdio.h>

int main() {
    int A, N;
    
    scanf("%d", &A);
    scanf("%d", &N);
    
    while (N <= 0) {
        scanf("%d", &N);
    }
    
    int soma = 0;
    for (int i = 0; i < N; i++) {
        soma += A + i;
    }
    
    printf("%d\n", soma);
    
    return 0;
}
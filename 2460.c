#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int fila[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }
    
    int M;
    scanf("%d", &M);
    
    int sairam[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", &sairam[i]);
    }
    
    int primeiro = 1;
    for (int i = 0; i < N; i++) {
        int encontrou = 0;
        for (int j = 0; j < M; j++) {
            if (fila[i] == sairam[j]) {
                encontrou = 1;
                break;
            }
        }
        if (!encontrou) {
            if (primeiro) {
                printf("%d", fila[i]);
                primeiro = 0;
            } else {
                printf(" %d", fila[i]);
            }
        }
    }
    printf("\n");
    
    return 0;
}
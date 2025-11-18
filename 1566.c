#include <stdio.h>
#include <stdlib.h>

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);
        int *alturas = (int*)calloc(231 + 1, sizeof(int)); // índice de 0 a 231
        int h;

        for (int i = 0; i < N; i++) {
            scanf("%d", &h);
            alturas[h]++;
        }

        int first = 1;
        for (int i = 20; i <= 230; i++) {
            while (alturas[i] > 0) {
                if (!first) printf(" ");
                printf("%d", i);
                first = 0;
                alturas[i]--;
            }
        }
        printf("\n");
        free(alturas);
    }

    return 0;
}

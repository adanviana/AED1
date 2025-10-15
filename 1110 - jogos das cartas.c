#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        int v[100], r[100], i = 0, f = n, k = 0, j;
        for (j = 0; j < n; j++) v[j] = j + 1;
        while (f - i > 1) {
            r[k++] = v[i++];
            v[f++] = v[i++];
        }
        printf("Discarded cards:");
        if (k) {
            printf(" %d", r[0]);
            for (j = 1; j < k; j++) printf(", %d", r[j]);
        }
        printf("\nRemaining card: %d\n", v[i]);
    }
    return 0;
}
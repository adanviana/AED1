#include <stdio.h>

int main() {
    double A, B, C;
    scanf("%lf %lf %lf", &A, &B, &C);

    double media = (A * 2.0 + B * 3.0 + C * 5.0) / 10.0;

    printf("MEDIA = %.1lf\n", media);

    return 0;
}

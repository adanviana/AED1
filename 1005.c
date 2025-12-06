#include <stdio.h>

int main() {
    double A, B;
    scanf("%lf %lf", &A, &B);

    double media = (A * 3.5 + B * 7.5) / 11.0;

    printf("MEDIA = %.5lf\n", media);

    return 0;
}

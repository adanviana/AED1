#include <stdio.h>

int main() {
    char nome[100];
    double salario, vendas;

    scanf("%s", nome);
    while (getchar() != '\n');
    scanf("%lf %lf", &salario, &vendas);

    double bonus = vendas * 15.0 / 100.0;

    printf("TOTAL = R$ %.2lf\n", salario + bonus);
    return 0;
}

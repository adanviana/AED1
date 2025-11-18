#include <stdio.h>

int main() {
    int teste, dias;
    float comida;

    scanf("%d", &teste);

    while (teste) {
        dias = 0;
        scanf("%f", &comida);

        while (comida > 1) {
            dias++;
            comida /= 2;
        }

        printf("%d dias\n", dias);

        teste--;
    }
}
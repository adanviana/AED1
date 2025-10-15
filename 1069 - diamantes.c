#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        char linha[1001];
        scanf("%s", linha);
        int contador = 0, diamantes = 0;
    for(int j = 0; linha[j] != '\0'; j++) {
            if(linha[j] == '<') contador++;
    else if(linha[j] == '>') {
            if(contador > 0) {
                    diamantes++;
                    contador--;
        }
        }
        }
        printf("%d\n", diamantes);
    }
    return 0;
}

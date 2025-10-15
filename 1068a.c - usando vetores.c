#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    char expr[1001];
    for (int i = 0; i < N; i++) {
        int topo = 0;
        int correto = 1;
        int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    if (c == '(') topo++;
        else if (c == ')') {
    if (topo == 0) {
        correto = 0;
        } else topo--;
            }
        }
    if (topo != 0) correto = 0;
    if (correto) printf("correct\n");
        else printf("incorrect\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

void posfixo(char *pre, char *in, int n) {
    if (n <= 0) return;
    
    char raiz = pre[0];
    int pos_raiz;
    
    for (pos_raiz = 0; pos_raiz < n; pos_raiz++) {
        if (in[pos_raiz] == raiz) {
            break;
        }
    }
    
    posfixo(pre + 1, in, pos_raiz);
    posfixo(pre + 1 + pos_raiz, in + pos_raiz + 1, n - pos_raiz - 1);
    
    printf("%c", raiz);
}

int main() {
    char pre[30], in[30];
    
    while (scanf("%s %s", pre, in) != EOF) {
        int n = strlen(pre);
        posfixo(pre, in, n);
        printf("\n");
    }
    
    return 0;
}
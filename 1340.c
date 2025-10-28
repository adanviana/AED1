#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int stack = 1, queue = 1, priority = 1;
        int pilha[1000], topo = -1;
        int fila[1000], inicio = 0, fim = -1;
        int fila_prioridade[1000], tam_prioridade = 0;
        int max_index;
        
    for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d", &op);
            
        if (op == 1) {
                scanf("%d", &x);
                if (stack) pilha[++topo] = x;
                if (queue) fila[++fim] = x;
                if (priority) fila_prioridade[tam_prioridade++] = x;
            } else {
                scanf("%d", &x);
                
                if (stack) {
                    if (topo < 0 || pilha[topo] != x) {
                        stack = 0;
                    } else {
                        topo--;
                    }
                }
                
                if (queue) {
                    if (inicio > fim || fila[inicio] != x) {
                        queue = 0;
                    } else {
                        inicio++;
                    }
                }
                
                if (priority) {
                    if (tam_prioridade <= 0) {
                        priority = 0;
                        continue;
                    }
                    
                    max_index = 0;
                    for (int j = 1; j < tam_prioridade; j++) {
                        if (fila_prioridade[j] > fila_prioridade[max_index]) {
                            max_index = j;
                        }
                    }
                    
                    if (fila_prioridade[max_index] != x) {
                        priority = 0;
                    } else {
                        for (int j = max_index; j < tam_prioridade - 1; j++) {
                            fila_prioridade[j] = fila_prioridade[j + 1];
                        }
                        tam_prioridade--;
                    }
                }
            }
        }
        
        int count = stack + queue + priority;
        
        if (count == 0) {
            printf("impossible\n");
        } else if (count > 1) {
            printf("not sure\n");
        } else if (stack) {
            printf("stack\n");
        } else if (queue) {
            printf("queue\n");
        } else {
            printf("priority queue\n");
        }
    }
    return 0;
}
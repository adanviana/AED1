#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char val;
    struct Node* next;
} Node;

void push(Node** topo, char c) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->val = c;
    novo->next = *topo;
    *topo = novo;
}

int pop(Node** topo) {
    if (*topo == NULL) return 0;
    Node* temp = *topo;
    *topo = (*topo)->next;
    free(temp);
    return 1;
}

int main() {
    char expr[1001];
    while (scanf(" %[^\n]", expr) != EOF) {
        Node* topo = NULL;
        int correto = 1;
        for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(') push(&topo, '(');
            else if (expr[i] == ')') {
        if (!pop(&topo)) {
                    correto = 0;
                    break;
                }
            }
        }
        if (topo != NULL) correto = 0;
        while (topo != NULL) pop(&topo);
        if (correto) printf("correct\n");
        else printf("incorrect\n");
    }
    return 0;
}

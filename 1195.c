#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *e, *d;
} No;

No* insere(No *r, int x) {
    if (!r) {
        r = (No*)malloc(sizeof(No));
        r->v = x;
        r->e = r->d = NULL;
        return r;
    }
    if (x < r->v) r->e = insere(r->e, x);
    else r->d = insere(r->d, x);
    return r;
}

void pre(No *r, int *f) {
    if (!r) return;
    if (!*f) printf(" ");
    printf("%d", r->v);
    *f = 0;
    pre(r->e, f);
    pre(r->d, f);
}

void in(No *r, int *f) {
    if (!r) return;
    in(r->e, f);
    if (!*f) printf(" ");
    printf("%d", r->v);
    *f = 0;
    in(r->d, f);
}

void pos(No *r, int *f) {
    if (!r) return;
    pos(r->e, f);
    pos(r->d, f);
    if (!*f) printf(" ");
    printf("%d", r->v);
    *f = 0;
}

void freeArvore(No *r) {
    if (!r) return;
    freeArvore(r->e);
    freeArvore(r->d);
    free(r);
}

int main() {
    int C, N, x;
    scanf("%d", &C);
    for (int c = 1; c <= C; c++) {
        scanf("%d", &N);
        No *r = NULL;
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            r = insere(r, x);
        }
        printf("Case %d:\n", c);
        int f = 1;
        printf("Pre.: ");
        pre(r, &f);
        printf("\n");
        f = 1;
        printf("In..: ");
        in(r, &f);
        printf("\n");
        f = 1;
        printf("Post: ");
        pos(r, &f);
        printf("\n\n");
        freeArvore(r);
    }
    return 0;
}

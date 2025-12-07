#include <stdio.h>
#include <stdlib.h>

#define MAX 200010

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX];
int pai[MAX], tam[MAX];

int comparar(const void *a, const void *b) {
    Aresta *arestaA = (Aresta *)a;
    Aresta *arestaB = (Aresta *)b;
    return arestaA->peso - arestaB->peso;
}

int encontrar(int x) {
    if (pai[x] == x) return x;
    return pai[x] = encontrar(pai[x]);
}

int unir(int x, int y) {
    x = encontrar(x);
    y = encontrar(y);
    
    if (x == y) return 0;
    
    if (tam[x] < tam[y]) {
        pai[x] = y;
        tam[y] += tam[x];
    } else {
        pai[y] = x;
        tam[x] += tam[y];
    }
    return 1;
}

int main() {
    int m, n;
    
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        
        int somaTotal = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
            somaTotal += arestas[i].peso;
        }
        
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            tam[i] = 1;
        }
        
        qsort(arestas, n, sizeof(Aresta), comparar);
        
        int somaMST = 0;
        int arestasUsadas = 0;
        
        for (int i = 0; i < n && arestasUsadas < m - 1; i++) {
            if (unir(arestas[i].u, arestas[i].v)) {
                somaMST += arestas[i].peso;
                arestasUsadas++;
            }
        }
        
        printf("%d\n", somaTotal - somaMST);
    }
    
    return 0;
}
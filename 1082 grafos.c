#include <stdio.h>

int grafo[26][26];
int visitado[26];
int componente[26];
int n_componente;

void dfs(int v, int comp) {
    visitado[v] = 1;
    componente[v] = comp;
    
    for (int i = 0; i < 26; i++) {
        if (grafo[v][i] && !visitado[i]) {
            dfs(i, comp);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int caso = 1; caso <= N; caso++) {
        int V, E;
        scanf("%d %d", &V, &E);
        
        for (int i = 0; i < 26; i++) {
            visitado[i] = 0;
            componente[i] = -1;
            for (int j = 0; j < 26; j++) {
                grafo[i][j] = 0;
            }
        }
        
        for (int i = 0; i < E; i++) {
            char v1, v2;
            scanf(" %c %c", &v1, &v2);
            int a = v1 - 'a';
            int b = v2 - 'a';
            grafo[a][b] = 1;
            grafo[b][a] = 1;
        }
        
        n_componente = 0;
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                dfs(i, n_componente);
                n_componente++;
            }
        }
        
        printf("Case #%d:\n", caso);
        
        for (int comp = 0; comp < n_componente; comp++) {
            for (int i = 0; i < V; i++) {
                if (componente[i] == comp) {
                    printf("%c,", 'a' + i);
                }
            }
            printf("\n");
        }
        
        printf("%d connected components\n\n", n_componente);
    }
    
    return 0;
}
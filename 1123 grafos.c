#include <stdio.h>

#define MAX 260
#define INF 1000000000

int main() {
    int N, M, C, K;
    
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;
        
        int grafo[MAX][MAX];
        int dist[MAX];
        int visitado[MAX];
        int custoRota[MAX];
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                grafo[i][j] = INF;
            }
            grafo[i][i] = 0;
        }
        
        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            grafo[U][V] = P;
            grafo[V][U] = P;
        }
        
        custoRota[C-1] = 0;
        for (int i = C-2; i >= 0; i--) {
            custoRota[i] = custoRota[i+1] + grafo[i][i+1];
        }
        
        for (int i = 0; i < C; i++) {
            for (int j = 0; j < N; j++) {
                if (j != i && j != i-1 && j != i+1) {
                    grafo[i][j] = INF;
                }
            }
        }
        
        for (int i = 0; i < C-1; i++) {
            for (int j = i+2; j < N; j++) {
                grafo[i][j] = INF;
            }
        }
        
        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            visitado[i] = 0;
        }
        
        dist[K] = 0;
        
        for (int count = 0; count < N; count++) {
            int u = -1;
            int min = INF;
            
            for (int i = 0; i < N; i++) {
                if (!visitado[i] && dist[i] < min) {
                    min = dist[i];
                    u = i;
                }
            }
            
            if (u == -1) break;
            
            visitado[u] = 1;
            
            for (int v = 0; v < N; v++) {
                if (!visitado[v] && grafo[u][v] != INF) {
                    if (dist[u] + grafo[u][v] < dist[v]) {
                        dist[v] = dist[u] + grafo[u][v];
                    }
                }
            }
        }
        
        int resposta = INF;
        for (int i = 0; i < C; i++) {
            if (dist[i] + custoRota[i] < resposta) {
                resposta = dist[i] + custoRota[i];
            }
        }
        
        printf("%d\n", resposta);
    }
    
    return 0;
}
#include <stdio.h>

#define MAX 501
#define INF 1000000000

int main() {
    int n, e;
    
    while (1) {
        scanf("%d %d", &n, &e);
        if (n == 0 && e == 0) break;
        
        int dist[MAX][MAX];
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) {
                    dist[i][j] = 0;
                } else {
                    dist[i][j] = INF;
                }
            }
        }
        
        for (int i = 0; i < e; i++) {
            int x, y, h;
            scanf("%d %d %d", &x, &y, &h);
            
            if (dist[y][x] != INF) {
                dist[x][y] = 0;
                dist[y][x] = 0;
            } else {
                dist[x][y] = h;
            }
        }
        
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 1; j <= n; j++) {
                    if (dist[k][j] == INF) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j && dist[i][j] != INF && dist[j][i] != INF) {
                    dist[i][j] = 0;
                }
            }
        }
        
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (dist[i][k] == INF) continue;
                for (int j = 1; j <= n; j++) {
                    if (dist[k][j] == INF) continue;
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int k;
        scanf("%d", &k);
        
        for (int i = 0; i < k; i++) {
            int o, d;
            scanf("%d %d", &o, &d);
            
            if (dist[o][d] == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", dist[o][d]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
#include <stdio.h>
#include <string.h>

int dx[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

int main() {
    char origem[3], destino[3];
    
    while (scanf("%s %s", origem, destino) != EOF) {
        int visitado[8][8] = {0};
        int fila_linha[64], fila_coluna[64], distancia[64];
        int ini = 0, fim = 0;
        
        int col_orig = origem[0] - 'a';
        int lin_orig = origem[1] - '1';
        int col_dest = destino[0] - 'a';
        int lin_dest = destino[1] - '1';
        
        fila_linha[fim] = lin_orig;
        fila_coluna[fim] = col_orig;
        distancia[fim] = 0;
        fim++;
        visitado[lin_orig][col_orig] = 1;
        
        while (ini < fim) {
            int lin_atual = fila_linha[ini];
            int col_atual = fila_coluna[ini];
            int dist_atual = distancia[ini];
            ini++;
            
            if (lin_atual == lin_dest && col_atual == col_dest) {
                printf("To get from %s to %s takes %d knight moves.\n", 
                       origem, destino, dist_atual);
                break;
            }
            
            for (int i = 0; i < 8; i++) {
                int novaLinha = lin_atual + dx[i];
                int novaColuna = col_atual + dy[i];
                
                if (novaLinha >= 0 && novaLinha < 8 && 
                    novaColuna >= 0 && novaColuna < 8 && 
                    !visitado[novaLinha][novaColuna]) {
                    
                    visitado[novaLinha][novaColuna] = 1;
                    fila_linha[fim] = novaLinha;
                    fila_coluna[fim] = novaColuna;
                    distancia[fim] = dist_atual + 1;
                    fim++;
                }
            }
        }
    }
    
    return 0;
}
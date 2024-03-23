#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "dijkstra.h"
int main() {
    int n, m, k, a, b, c;
    printf("Digite o número de cidades: \n"); //quantidade de vértices
    scanf("%d", &n);
    printf("Digite o número de vôos: \n"); //quantidade de arestas
    scanf("%d", &m);
    printf("Digite o parâmetro k: \n"); //quantidade de caminhos mínimos a serem encontrados na saída
    scanf("%d", &k);
    Grafo *grafo = cria_grafo(n); //chama a função cria grafo, enviando o numero de vertices como parametro
    for(int i=0; i<m; i++){
        printf("Digite a cidade de origem, destino e o custo do %dº vôo: \n", i+1);
        scanf("%d%d%d", &a, &b, &c);
        cria_aresta(grafo, a - 1, b - 1, c); //o vértice da cidade 1 estará na posição 0 do array
    }



    
    libera_grafo(grafo);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo *cria_grafo(int total_vertices){
    Grafo *grafo = (Grafo *)malloc(sizeof(Grafo)); //aloca o grafo
    grafo->total_vertices = total_vertices; //salva o numero de vertices na variavel total_vertices
    grafo->vertices = (Vertice *)malloc(total_vertices * sizeof(Vertice)); //aloca a quantidade de vertices do grafo
    for(int i=0; i<total_vertices; i++){ //inicia o numero de arestas saindo de cada aresta como 0 e o ponteiro do array de arestas como NULL
        grafo->vertices[i].total_arestas = 0;
        grafo->vertices[i].arestas = NULL;
    }
    return grafo;
}
void cria_aresta(Grafo *grafo, int origem, int destino, int peso){
    grafo->vertices[origem].arestas = (Aresta *)realloc(grafo->vertices[origem].arestas, grafo->vertices[origem].total_arestas + 1 * sizeof(Aresta)); //esta realocando o array de arestas para caber a nova aresta que esta sendo criada.
    grafo->vertices[origem].arestas[grafo->vertices[origem].total_arestas].destino = destino; //o total_arestas é o indice da nova aresta, portanto estamos colocando o vertice destino como destino da aresta
    grafo->vertices[origem].arestas[grafo->vertices[origem].total_arestas].peso = peso; //atribuindo o peso da aresta
    grafo->vertices[origem].total_arestas++;
}
void libera_grafo(Grafo *grafo) {
    for (int i = 0; i < grafo->total_vertices; i++) {
        free(grafo->vertices[i].arestas);
    }
    free(grafo->vertices);
    free(grafo);
}


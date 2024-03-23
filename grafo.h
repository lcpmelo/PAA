#ifndef graph_h
#define graph_h
typedef struct{
    int origem, destino, peso;
} Aresta;
typedef struct{
    Aresta* arestas;
    int total_arestas;
} Vertice;
typedef struct{
    Vertice* vertices;
    int total_vertices;
} Grafo;
Grafo *cria_grafo(int total_vertices);
void cria_aresta(Grafo *grafo, int origem, int destino, int peso);
void libera_grafo(Grafo *grafo);
#endif

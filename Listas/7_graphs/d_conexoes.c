#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10000

typedef struct
{
    int v, w;
} Edge;

Edge edge(int a, int b)
{
    Edge e = {a, b};
    return e;
}

typedef struct graph
{
    int V, E;
    int **adj;
    int **tc;
} graph, *Graph;

static int **matrixInit(int r, int c, int val)
{
    int **m = malloc(r * sizeof(int *));
    for (int i = 0; i < r; ++i)
        m[i] = malloc(c * sizeof(int));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            m[i][j] = val;
    return m;
}

Graph init(int V)
{
    Graph G = malloc(sizeof(graph));
    G->V = V;
    G->E = 0;
    G->adj = matrixInit(V, V, 0);
    return G;
}

void insert(Graph G, Edge e)
{
    int v = e.v, w = e.w;
    if (G->adj[v][w] == 0)
        G->E++;
    G->adj[v][w] = 1;
}

void graphTC(Graph G)
{
    int i, s, t;
    G->tc = matrixInit(G->V, G->V, 0);
    for (s = 0; s < G->V; s++)
    {
        for (t = 0; t < G->V; t++)
        {
            G->tc[s][t] = G->adj[s][t];
        }
    }
    for (s = 0; s < G->V; s++)
        G->tc[s][s] = 1;

    for (i = 0; i < G->V; i++)
        for (s = 0; s < G->V; s++)
            if (G->tc[s][i] == 1)
                for (t = 0; t < G->V; t++)
                    if (G->tc[i][t] == 1)
                        G->tc[s][t] = 1;
}

int graphSearch(Graph G, int s, int t)
{
    return G->tc[s][t];
}

int main(void)
{
    int M, V;
    scanf("%d", &V);
    Graph G = init(V);
    
    while (1)
    {
        int v, w, d;

        scanf("%d %d %d", &v, &w, &d);

        if (v == 0 && w == 0 && d == 0)
            break;

        insert(G, edge(v, w));

        if (d == 2)
        {
            insert(G, edge(w, v));
        }
    }

    graphTC(G);
    int t, x;

    while (scanf("%d %d", &t, &x) == 2)
    {
        int c1 = graphSearch(G, t, x);
        int c2 = graphSearch(G, x, t);

        if (c1 && c1 == c2)
            printf("Ida e Volta\n");
        else if (c1 == 1)
            printf("Apenas Ida\n");
        else if (c2 == 1)
            printf("Apenas Volta\n");
        else
            printf("Impossibru\n");
    }

    return 0;
}
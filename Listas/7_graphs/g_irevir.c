#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define maxV 10000

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

Graph graphInit(int V)
{
    Graph G = malloc(sizeof(graph));
    G->V = V;
    G->E = 0;
    G->adj = matrixInit(V, V, 0);
    return G;
}

void graphInsert(Graph G, Edge e)
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

int graphSearchTC(Graph G, int s, int t)
{
    return G->tc[s][t];
}

int main(void)
{
    int M, N;

    while (scanf("%d %d", &N, &M) && M && N)
    {
        Graph G = graphInit(N);

        for (int i = 0; i < M; i++)
        {
            int v, w, p;
            scanf("%d %d %d", &v, &w, &p);
            graphInsert(G, edge(v - 1, w - 1));

            if (p == 2)
            {
                graphInsert(G, edge(w - 1, v - 1));
            }
        }

        graphTC(G);

        int c = 0, g = 0, f = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++, c++)
            {
                if (graphSearchTC(G, i, j) + graphSearchTC(G, j, i) == 2)
                    g++;
                else
                {
                    f = 1;
                    break;
                }
            }
            if (f)
                break;
        }

        if (f)
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

typedef struct node *link;

struct node
{
    int v;
    link next;
};

typedef struct
{
    int v, w;
} Edge;

typedef struct graph
{
    int V, E;
    link *adj;
} graph, *Graph;

Edge edge(int a, int b)
{
    Edge e = {a, b};
    return e;
}

link newLink(int v, link next)
{
    link x = malloc(sizeof(link));
    if (x == NULL)
        exit(0);

    x->v = v;
    x->next = next;

    return x;
}

Graph init(int V)
{
    int v;

    Graph G = malloc(sizeof(*G));

    G->V = V;
    G->E = 0;
    G->adj = malloc(V * sizeof(link));

    for (v = 0; v < V; ++v)
        G->adj[v] = NULL;

    return G;
}

void insert(Graph G, Edge e)
{
    int v = e.v, w = e.w;

    G->adj[v] = newLink(w, G->adj[v]);
    G->adj[w] = newLink(v, G->adj[w]);
    G->E++;
}

int pre[MAX];

static int cnt = 0;

void dfsR(Graph G, Edge e)
{
    int t, w = e.w;
    link l;
    pre[w] = cnt++;

    for (l = G->adj[w]; l != NULL; l = l->next)
    {
        t = l->v;
        if (pre[t] == -1)
            dfsR(G, edge(w, t));
    }
}

int search(Graph G)
{
    int v;
    cnt = 0;
    int conexos = 0;

    for (v = 0; v < G->V; v++)
        pre[v] = -1;

    for (v = 0; v < G->V; v++)
    {
        if (pre[v] == -1)
        {
            dfsR(G, edge(v, v));
            conexos++;
        }
    }

    return conexos;
}

void printGraph(graph *graph)
{
    int v;

    for (v = 0; v < graph->V; v++)
    {
        struct node *temp = graph->adj[v];

        printf("\n Vertex %d\n: ", v);

        while (temp)
        {
            printf("%d -> ", temp->v);
            temp = temp->next;
        }

        printf("\n");
    }
}

int main()
{
    int V;

    scanf("%d", &V);

    Graph graph = init(V);

    int v, w;

    while (scanf("%d %d", &v, &w) != EOF)
    {
        insert(graph, edge(v, w));
    }

    int a = search(graph);

    printf("%d\n", a);

    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100000

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

link new(int v, link next)
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
    G->adj[v] = new(w, G->adj[v]);
    G->adj[w] = new(v, G->adj[w]);
    G->E++;
}

int pre[MAX];      
static int cnt = 0;
static int cmp = 0;

void dfsR(Graph G, Edge e)
{
    int t, w = e.w;
    link l;
    pre[w] = cnt++;
    cmp++;
    
    for (l = G->adj[w]; l != NULL; l = l->next)
    {
        t = l->v;
        if (pre[t] == -1)
        {
            dfsR(G, edge(w, t));
        }
    }
}

int graphSearch(Graph G)
{
    int v, max = -1;
    cnt = 0;

    for (v = 0; v < G->V; v++)
    {
        pre[v] = -1;
    }

    for (v = 0; v < G->V; v++)
    {
        cmp = 0;
        if (pre[v] == -1)
        {
            dfsR(G, edge(v, v));
            if (v == 0)
                max = cmp;
            else if (cmp > max)
                max = cmp;
        }
    }

    return max;
}

int search(char **v, int n, char *s)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(v[i], s) == 0)
            return i;
    }
}

int main(void)
{
    int C, R;

    while (scanf("%d %d%*c", &C, &R) && (C || R))
    {
        char **v = malloc(sizeof(char *) * C);

        for (int i = 0; i < C; i++)
        {
            char *s = malloc(sizeof(char) * 31);
            scanf(" %s", s);
            v[i] = s;
        }

        Graph G = init(C);

        for (int i = 0; i < R; i++)
        {
            char s1[31], s2[31];
            scanf("%s %s", s1, s2);
            int a, b;
            a = search(v, C, s1);
            b = search(v, C, s2);
            insert(G, edge(a, b));
        }

        int val = graphSearch(G);

        printf("%d\n", val);
    }

    return 0;
}
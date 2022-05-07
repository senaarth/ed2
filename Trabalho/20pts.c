#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hash
{
    int trafego;
    int index;
} hash;

typedef hash Item;
#define Key (A)(A.trafego)
#define less(A, B)              \
    {                           \
        if (Key(A) == Key(B))   \
        {                       \
            (A.index < B.index) \
        }                       \
        else                    \
        {                       \
            Key(A) < Key(B)     \
        }                       \
    }
#define lesseq(A, B) ((A.trafego) <= (B.trafego))
#define exch(A, B) \
    {              \
        Item t;    \
        t = A;     \
        A = B;     \
        B = t;     \
    }
#define cmpexch(A, B)   \
    {                   \
        if (less(B, A)) \
            exch(A, B); \
    }

void merge(Item *V, int l, int m, int r)
{
    Item R = malloc(sizeof(Item)(r - l + 1));
    int i = l, j = m + 1, k = 0;

    while (i <= m && j <= r)
    {
        if (lesseq(V[i], V[j]))
            R[k++] = V[i++];
        else
            R[k++] = V[j++];
    }

    while (i <= m)
        R[k++] = V[i++];
    while (j <= r)
        R[k++] = V[j++];

    k = 0;
    for (i = l; i <= r; i++)
        V[i] = R[k++];
    free(R);
}

void mergesort(Item *V, int l, int r)
{
    if (l >= r)
        return;
    int meio = (l + r) / 2;
    mergesort(V, l, meio);
    mergesort(V, meio + 1, r);
    merge(V, l, meio, r);
}

int main()
{
    int A, V;
    int x, y;
    int cont = 1;
    hash hash[100];

    while (scanf("%d %d", &A, &V) == 2)
    {
        if (A == 0 && V == 0)
            break;

        for (int i = 1; i <= A; i++)
        {
            hash[i].index = i;
            hash[i].trafego = 0;
        }
        for (int i = 0; i < V; i++)
        {
            scanf("%d %d", &x, &y);
            hash[x].trafego++;
            hash[y].trafego++;
        }
        printf("Teste %d\n", cont);
        mergesort(hash, 1, A);
        for (int i = 1; i <= A; i++)
        {
            if (hash[i].trafego == hash[A].trafego)
            {
                printf("%d ", hash[i].index);
            }
        }
        printf("\n\n");
        cont++;
    }
    return 0;
}
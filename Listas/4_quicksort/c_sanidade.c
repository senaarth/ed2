#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    unsigned long long address;
    unsigned long long prev;
    unsigned long long next;
} Node;

void exchange(Node *v, int x, int y)
{
    Node tmp = v[x];
    v[x] = v[y];
    v[y] = tmp;
}

void cmpexch(Node *v, int x, int y)
{
    if (v[y].address < v[x].address)
    {
        exchange(v, x, y);
    }
}

int separa(Node *v, int l, int r)
{
    unsigned long long c = v[r].address;
    int j = l;
    int k;

    for (k = l; k < r; k++)
    {
        if (v[k].address < c)
        {
            exchange(v, k, j);
            j++;
        }
    }

    exchange(v, k, j);

    return j;
}

void quicksort(Node *v, int l, int r)
{
    int j;

    if (r <= l)
        return;

    cmpexch(v, (l + r) / 2, r);
    cmpexch(v, l, (l + r) / 2);
    cmpexch(v, r, (l + r) / 2);

    j = separa(v, l, r);

    quicksort(v, l, j - 1);
    quicksort(v, j + 1, r);
}

int search(Node v[], int l, int r, unsigned long long address)
{
    int i = (l + r) / 2;

    if (l > r || address <= 0)
        return -1;

    if (v[i].address == address)
        return i;

    if (v[i].address < address)
    {
        return search(v, i + 1, r, address);
    }
    else
    {
        return search(v, l, i - 1, address);
    }
}

int main()
{
    Node v[250001];
    int stack[250001];
    int i = 0;
    unsigned long long x, prev, next, ptr1, ptr2;

    for (i = 0; scanf("%llx %llx %llx", &x, &prev, &next) != EOF; i++)
    {
        v[i].address = x;
        v[i].prev = prev;
        v[i].next = next;
    }

    ptr1 = v[0].address;
    ptr2 = v[1].address;

    quicksort(v, 0, i);

    int index1 = search(v, 0, i, ptr1);
    int index2 = search(v, 0, i, ptr2);

    int path[250001];
    int index_aux = index1, j = 0;

    while (index_aux != -1)
    {
        path[j++] = index_aux;

        index_aux = search(v, 0, i, v[index_aux].next);
    }

    // for (int m = 0; m < j; m++)
    //     printf("%d\n", path[m]);

    index_aux = index2;

    while (j != 0)
    {
        if (index_aux == -1)
            break;

        if (index_aux != path[j - 1])
        {
            printf("insana\n");
            return 0;
        }

        index_aux = search(v, 0, i, v[index_aux].prev);
        j--;
    }

    printf("sana\n");
    return 0;
}
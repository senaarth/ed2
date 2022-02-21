#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    unsigned long long address;
    unsigned long long prev;
    unsigned long long next;
} Node;

void merge(Node *v, int l, int r1, int r2)
{
    Node *aux_v = malloc(sizeof(Node) * (r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2)
    {
        if (v[i].address < v[j].address)
            aux_v[k++] = v[i++];
        else
            aux_v[k++] = v[j++];
    }

    while (i <= r1)
        aux_v[k++] = v[i++];

    while (j <= r2)
        aux_v[k++] = v[j++];

    k = 0;
    for (i = l; i <= r2; i++)
        v[i] = aux_v[k++];

    free(aux_v);
}

void merge_sort(Node *v, int l, int r)
{
    if (l >= r)
        return;

    int middle = (l + r) / 2;

    merge_sort(v, l, middle);
    merge_sort(v, middle + 1, r);
    merge(v, l, middle, r);
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

    merge_sort(v, 0, i);

    int index1 = search(v, 0, i, ptr1);          // i do ptr1
    int prev1 = search(v, 0, i, v[index1].prev); // i do anterior ao ptr1

    int index2 = search(v, 0, i, ptr2);          // i do ptr2
    int next2 = search(v, 0, i, v[index2].next); // i do proximo ao ptr2

    v[prev1].next = v[index2].next;
    v[next2].prev = v[index1].prev;

    v[index1].prev = 0;
    v[index2].next = 0;

    int j = 0;

    while (prev1 != -1)
    {
        stack[j++] = prev1;

        prev1 = search(v, 0, i, v[prev1].prev);
    }

    for (j = j - 1; j > 0; j--)
    {
        printf("%llx %llx %llx\n", v[stack[j]].address, v[stack[j]].prev, v[stack[j]].next);
    }

    prev1 = stack[0];

    while (prev1 != -1)
    {
        printf("%llx %llx %llx\n", v[prev1].address, v[prev1].prev, v[prev1].next);
        prev1 = search(v, 0, i, v[prev1].next);
    }

    printf("\n");

    while (1)
    {
        printf("%llx\n", v[index1].address);

        if (v[index1].address == ptr2)
            break;

        index1 = search(v, 0, i, v[index1].next);
    }

    return 0;
}
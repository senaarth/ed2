#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry
{
    int value;
    int og_index;
} Entry;

void merge(Entry *v, int l, int r1, int r2)
{
    Entry *aux_v = malloc(sizeof(Entry) * (r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2)
    {
        if (v[i].value < v[j].value)
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

void merge_sort(Entry *v, int l, int r)
{
    if (l >= r)
        return;

    int middle = (l + r) / 2;

    merge_sort(v, l, middle);
    merge_sort(v, middle + 1, r);
    merge(v, l, middle, r);
}

int search(Entry v[], int l, int r, int value)
{
    int i = (l + r) / 2;

    if (l > r)
        return -1;

    if (v[i].value == value)
        return i;

    if (v[i].value < value)
    {
        return search(v, i + 1, r, value);
    }
    else
    {
        return search(v, l, i - 1, value);
    }
}

int main()
{
    int n, m, x;

    scanf("%d %d", &n, &m);

    Entry *v = malloc(n * sizeof(Entry));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        v[i].value = x;
        v[i].og_index = i;
    }

    merge_sort(v, 0, n - 1);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);

        int index = search(v, 0, n - 1, x);

        if (index == -1)
            printf("-1\n");
        else
            printf("%d\n", v[index].og_index);
    }

    return 0;
}

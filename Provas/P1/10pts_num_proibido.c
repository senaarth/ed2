#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(unsigned long long *v, int l, int r1, int r2)
{
    unsigned long long *aux_v = malloc(sizeof(unsigned long long) * (r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2)
    {
        if (v[i] < v[j])
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

void merge_sort(unsigned long long*v, int l, int r)
{
    if (l >= r)
        return;

    int middle = (l + r) / 2;

    merge_sort(v, l, middle);
    merge_sort(v, middle + 1, r);
    merge(v, l, middle, r);
}

int search(unsigned long long v[], int l, int r, unsigned long long value)
{
    int i = (l + r) / 2;

    if (l > r)
        return -1;

    if (v[i] == value)
        return i;

    if (v[i] < value)
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
    int n, x;

    scanf("%d", &n);

    unsigned long long *v = malloc(n * sizeof(unsigned long long));

    for (int i = 0; i < n; i++)
    {
        scanf("%lli", &v[i]);
    }

    merge_sort(v, 0, n - 1);

    while (scanf("%d", &x) != EOF)
    {
        if (search(v, 0, n, x) != -1)
            printf("sim\n");
        else
            printf("nao\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int r1, int r2)
{
    int *aux_v = malloc(sizeof(int) * (r2 - l + 1));
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

void merge_sort(int *v, int l, int r)
{
    if (l >= r)
        return;

    int middle = (l + r) / 2;

    merge_sort(v, l, middle);
    merge_sort(v, middle + 1, r);
    merge(v, l, middle, r);
}

int search(int v[], int l, int r, int value)
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

int rm_repeated(int *v, int n)
{
    int k = 0;

    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[k])
            v[++k] = v[i];
    }

    return k;
}

int *intercala(int *a, int *b, int n, int m)
{
    int i = 0, j = 0;
    int *c = (int *)malloc((n + m) * sizeof(int));
    int k = 0;

    while ((i + j) < (n + m))
    {
        if (i >= n)
        {
            for (; j < m; j++, k++)
            {
                c[k] = b[j];
            }

            break;
        }
        else if (j >= m)
        {
            for (; i < n; i++, k++)
            {
                c[k] = a[i];
            }
            break;
        }

        if (a[i] < b[j])
            c[k] = a[i++];
        else
            c[k] = b[j++];

        k++;
    }

    return c;
}

int main()
{
    int num, v[200000];
    int n = 0, n2 = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    merge_sort(v, 0, n - 1);

    n2 = rm_repeated(v, n);

    if (n2 % 2 == 0)
        v[++n2] = 1000000000;

    int nmu[66000], nmui = -1;

    for (int i = 0; i <= n2; i += 2)
    {
        nmu[++nmui] = v[i] + v[i + 1];

        if (search(v, 0, n2, nmu[nmui]) != -1)
            nmui--;
    }

    int *c = intercala(v, nmu, n2 + 1, nmui + 1);

    for (int i = 0; i <= (n2 + nmui + 1); i += 4)
        printf("%d\n", c[i]);

    printf("Elementos: %d\n", n2 + nmui + 2);

    return 0;
}

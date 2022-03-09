#include <stdio.h>
#include <stdlib.h>

void exchange(int *v, int x, int y)
{
    int tmp = v[x];
    v[x] = v[y];
    v[y] = tmp;
}

void cmpexch(int *v, int x, int y)
{
    if (v[y] < v[x])
    {
        exchange(v, x, y);
    }
}

int separa(int *v, int l, int r)
{
    int c = v[r];
    int j = l;
    int k;

    for (k = l; k < r; k++)
    {
        if (v[k] < c)
        {
            exchange(v, k, j);
            j++;
        }
    }

    exchange(v, k, j);

    return j;
}

void quicksort(int *v, int l, int r)
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

int main()
{
    int n;

    scanf("%d", &n);

    int *v = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    quicksort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }

    printf("\n");

    return 0;
}

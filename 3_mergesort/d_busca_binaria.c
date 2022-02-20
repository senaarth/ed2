#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int *v, int l, int r, int value)
{
    int i = (l + r) / 2;

    if (v[i] == value)
        return i;

    if (v[i] < value)
    {
        if (v[i + 1] > value)
            return i + 1;

        return search(v, i + 1, r, value);
    }
    else
    {
        if (v[i + 1] < value)
            return i - 1;

        return search(v, l, i - 1, value);
    }
}

int main()
{
    int n, m, x;

    scanf("%d %d", &n, &m);

    int *v = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);

        if (x > v[n - 1])
        {
            printf("%d\n", n);
        }

        if (x <= v[0])
        {
            printf("0\n");
        }

        if (x <= v[n - 1] && x > v[0])
        {
            int index = search(v, 0, n - 1, x);

            printf("%d\n", index);
        }
    }

    return 0;
}

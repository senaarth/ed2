// ISSO AQUI DEU TLE, O IDEAL SERIA COLOCAR UM QUICK SELECT ALI NA LINHA 103 ONDE EU COLOQUEI UM SEPARA!

#include <stdio.h>
#include <stdlib.h>

typedef struct Seed
{
    long long code;
    long long score;
} Seed;

void exchange(Seed *v, int x, int y)
{
    Seed tmp = v[x];
    v[x] = v[y];
    v[y] = tmp;
}

void cmpexch(Seed *v, int x, int y)
{
    if (v[y].code < v[x].code)
    {
        exchange(v, x, y);
    }
}

void cmpexch_score(Seed *v, int x, int y)
{
    if (v[y].score < v[x].score)
    {
        exchange(v, x, y);
    }
}

int separa(Seed *v, int l, int r, int type)
{
    Seed c = v[r];
    int j = l;
    int k;

    for (k = l; k < r; k++)
    {
        if (type == 0 && v[k].code < c.code)
        {
            exchange(v, k, j);
            j++;
        }

        if (type == 1 && v[k].score < c.score)
        {
            exchange(v, k, j);
            j++;
        }
    }

    exchange(v, k, j);

    return j;
}

void quicksort(Seed *v, int l, int r, int type)
{
    int j;

    if (r <= l)
        return;

    if (type == 0)
    {
        cmpexch(v, (l + r) / 2, r);
        cmpexch(v, l, (l + r) / 2);
        cmpexch(v, r, (l + r) / 2);
    }
    else
    {
        cmpexch_score(v, (l + r) / 2, r);
        cmpexch_score(v, l, (l + r) / 2);
        cmpexch_score(v, r, (l + r) / 2);
    }

    j = separa(v, l, r, type);

    quicksort(v, l, j - 1, type);
    quicksort(v, j + 1, r, type);
}

int search(Seed v[], int l, int r, long long score, long long code)
{
    int i = (l + r) / 2;
    Seed *v_aux = v;

    if (l > r)
        return -1;

    if (v[i].score == score)
    {
        if (v[i].code > code)
        {
            return i;
        }
        else
        {
            int i_by_code = separa(v_aux, l, r, 0);
            return i_by_code;
        }
    }

    if (v[i].score > score)
        return i;
    else
        return search(v, i + 1, r, score, code);
}

int main()
{
    int n, m = 0;
    long long code, score;

    scanf("%d", &n);

    Seed *v = malloc(sizeof(Seed) * n);

    while (scanf("%lld %lld", &code, &score) != EOF)
    {
        if (m < n)
        {
            v[m].code = code;
            v[m].score = score;
            m++;
        }
        else
        {
            quicksort(v, 0, m, 1);

            int index = search(v, 0, m - 1, score, code);

            if (index != -1)
            {
                v[index].code = code;
                v[index].score = score;
            }
        }
    }

    quicksort(v, 0, m - 1, 0);

    for (int i = 0; i < m; i++)
    {
        printf("%lld %lld\n", v[i].code, v[i].score);
    }

    return 0;
}
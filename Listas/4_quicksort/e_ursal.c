#include <stdio.h>
#include <stdlib.h>

typedef struct voto
{
    int candidato;
    int quantidade;
} voto;

void exchange(voto *a, voto *b)
{
    voto aux = *a;
    *a = *b;
    *b = aux;
}

int compare(voto a, voto b)
{

    if (a.quantidade > b.quantidade)
    {
        return 1;
    }
    else if (a.quantidade == b.quantidade)
    {
        if (a.candidato > b.candidato)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int separa(voto *v, int left, int right)
{
    int i = left - 1, j = right;
    voto c = v[right];
    while (1)
    {
        while (compare(v[++i], c))
            ;
        while (compare(c, v[--j]))
            if (j == left)
                break;
        if (i >= j)
            break;
        exchange(&v[i], &v[j]);
    }
    exchange(&v[i], &v[right]);
    return i;
}

void quicksort(voto *v, int left, int right)
{
    if (right <= left)
        return;

    int j;
    int i = (left + right) / 2;

    if (compare(v[right], v[i]))
    {
        exchange(&v[right], &v[i]);
    }

    if (compare(v[i], v[left]))
    {
        exchange(&v[i], &v[left]);
    }

    if (compare(v[i], v[left]))
    {
        exchange(&v[i], &v[right]);
    }

    j = separa(v, left, right);
    quicksort(v, left, j - 1);
    quicksort(v, j + 1, right);
}

int main()
{
    int s, f, e, n;
    voto *votos = calloc(100000, sizeof(voto));
    int contInv = 0, contVal = 0, contPres = 0;

    scanf("%d %d %d", &s, &f, &e);

    while (scanf("%d", &n) != EOF)
    {
        if (n < 0)
        {
            contInv++;
        }
        else
        {
            votos[n].candidato = n;
            votos[n].quantidade++;

            if (n < 100)
            {
                contPres++;
            }

            contVal++;
        }
    }

    printf("%d %d\n", contVal, contInv);

    quicksort(votos, 10, 99);
    quicksort(votos, 100, 999);
    quicksort(votos, 1000, 9999);
    quicksort(votos, 10000, 99999);

    float porcentagem = (votos[10].quantidade * 1.0) / (contPres * 1.0);

    if (porcentagem > 0.5)
    {
        printf("%d\n", votos[10].candidato);
    }
    else
    {
        printf("Segundo turno\n");
    }

    printf("%d", votos[100].candidato);

    for (int i = 101; i < 100 + s; i++)
    {
        printf(" %d", votos[i].candidato);
    }

    printf("\n");
    printf("%d", votos[1000].candidato);

    for (int i = 1001; i < 1000 + f; i++)
    {
        printf(" %d", votos[i].candidato);
    }

    printf("\n");
    printf("%d", votos[10000].candidato);

    for (int i = 10001; i < 10000 + e; i++)
    {
        printf(" %d", votos[i].candidato);
    }
    printf("\n");

    return 0;
}

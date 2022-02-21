#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Occurrence
{
    char drink_char;
    int index;
    int amount;
} Occurence;

void merge(Occurence *v, int l, int r1, int r2)
{
    Occurence *aux_v = malloc(sizeof(Occurence) * (r2 - l + 1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2)
    {
        if (v[i].amount >= v[j].amount)
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

void merge_sort(Occurence *v, int l, int r)
{
    if (l >= r)
        return;

    int middle = (l + r) / 2;

    merge_sort(v, l, middle);
    merge_sort(v, middle + 1, r);
    merge(v, l, middle, r);
}

int main()
{
    char *string = malloc(100001 * sizeof(char));
    Occurence *drinks = malloc(sizeof(Occurence));

    int i = 0, j = 0;
    char aux;

    while (scanf("%c", &string[i]) != EOF)
    {
        if (string[i] == '\n')
            break;

        if (string[i] == aux)
        {
            drinks[j - 1].amount++;
        }
        else
        {
            j++;

            drinks = realloc(drinks, j * sizeof(Occurence));

            drinks[j - 1].index = i;
            drinks[j - 1].drink_char = string[i];
            drinks[j - 1].amount = 1;
        }

        aux = string[i];
        i++;
    }

    merge_sort(drinks, 0, j - 1);

    for (int k = 0; k < j; k++)
    {
        printf("%d %c %d\n", drinks[k].amount, drinks[k].drink_char, drinks[k].index);
    }

    return 0;
}
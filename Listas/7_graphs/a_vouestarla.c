#include <stdio.h>
#include <stdlib.h>

int matrix[2000][2000];
int places[2000];

int main()
{
    int n, m, j, aux, danger;

    scanf("%d %d %d", &n, &m, &j);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &matrix[i][0]);

        for (int k = 1; k <= matrix[i][0]; k++)
            scanf("%d", &matrix[i][k]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &aux);

        places[aux] = 1;

        for (int k = 1; k <= matrix[aux][0]; k++)
        {
            danger = matrix[aux][k];
            places[danger] = 1;
        }
    }

    for (int i = 0; i < j; i++)
    {
        scanf("%d", &aux);
        if (places[aux] == 1)
            printf("Eu vou estar la\n");
        else
            printf("Nao vou estar la\n");
    }

    return 0;
}
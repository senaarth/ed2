#include <stdio.h>
#include <string.h>

#define MAX 1010

int matrix[MAX][MAX], visited[MAX], distances[MAX];

int n, m;

int shortest_path()
{
    distances[0] = 0;

    while (1)
    {
        int k = -1;

        for (int i = 0; i < n; i++)
        {
            if ((k == -1 || distances[i] < distances[k]) && !visited[i])
                k = i;
        }

        if (k == -1)
            break;

        visited[k] = 1;

        for (int i = 0; i < n; i++)
        {
            if ((distances[k] + matrix[k][i]) < distances[i])
                distances[i] = distances[k] + matrix[k][i];
        }
    }

    return distances[n - 1];
}

int main()
{
    int s, t, b;

    for (int i = 0; i < MAX; i++) {
        distances[i] = 99999999;
        visited[i] = 0;
    }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matrix[i][j] = 99999999;
        }
    }

    scanf("%d %d", &n, &m);

    n += 2;

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &s, &t, &b);
        // há um caminho de s até t
        // contendo b buracos
        matrix[s][t] = matrix[t][s] = b;
    }

    printf("%d\n", shortest_path());

    return 0;
}
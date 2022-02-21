#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Command
{
    int code;
    char cmd[16];
} Command;

void cmp_exch(Command vector[], int i)
{
    if (vector[i].code < vector[i - 1].code)
    {
        Command tmp = vector[i - 1];
        vector[i - 1] = vector[i];
        vector[i] = tmp;
    }
}

void sort(Command vector[], int l, int r)
{
    for (int i = r; i > l; i--)
    {
        cmp_exch(vector, i);
    }

    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        Command tmp = vector[j];

        while (tmp.code < vector[j - 1].code)
        {
            vector[j] = vector[j - 1];
            j--;
        }

        vector[j] = tmp;
    }
}

int search(Command v[], int l, int r, int code)
{
    int i = (l + r) / 2;

    if (l > r)
        return -1;

    if (v[i].code == code)
        return i;

    if (v[i].code < code)
    {
        return search(v, i + 1, r, code);
    }
    else
    {
        return search(v, l, i - 1, code);
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    Command *v = malloc(n * sizeof(Command));
    int code;
    char cmd[16];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %s", &code, cmd);
        v[i].code = code;
        strcpy(v[i].cmd, cmd);
    }

    sort(v, 0, n - 1);

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d\n", v[i].code);
    // }

    int userCmd;

    while (scanf("%d", &userCmd) != EOF)
    {
        int j = search(v, 0, n - 1, userCmd);

        if (j == -1)
        {
            printf("undefined\n");
        }
        else
        {
            printf("%s\n", v[j].cmd);
        }
    }

    return 0;
}
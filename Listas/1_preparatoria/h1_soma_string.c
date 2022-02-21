#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[99];
    int size;

    scanf("%d", &size);

    int sumArr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%s", str);

        int sum = 0;

        for (int j = 0; j < strlen(str); j++)
        {
            if (isdigit(str[j]))
            {
                int value = ((int)str[j]) - 48;
                sum += value;
            }
        }

        sumArr[i] = sum;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", sumArr[i]);
    }

    return 0;
}
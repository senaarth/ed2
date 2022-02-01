#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count(char *string)
{
    return *string == '\0'
               ? 0
               : count(string + 1) + (*string == '7');
}

int main()
{
    char string[1024];

    scanf("%s", string);

    int occurences = count(string);

    printf("%d\n", occurences);

    return 0;
}
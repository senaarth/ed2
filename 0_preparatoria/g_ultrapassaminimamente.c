#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head, *current;

void push(int data)
{
    node *new;
    new = malloc(sizeof(node));
    new->data = data;

    current = head->next;
    head->next = new;
    new->next = current;
}

int main()
{
    int *v, x, limit, n = 0, j = 0, sum = 0;

    v = malloc(sizeof(int));
    head = malloc(sizeof(node));
    head->next = NULL;

    while (x != 0)
    {
        scanf(" %d", &x);
        v[n] = x;
        n++;
        v = realloc(v, (n + 1) * sizeof(int));
    }

    scanf(" %d", &limit);

    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum > limit)
        {
            sum = 0;
            push(v[i]);
            j++;
        }
    }

    head = head->next;

    for (int i = 0; i < j; i++)
    {
        printf("%d\n", head->data);
        head = head->next;
    }

    return 0;
}
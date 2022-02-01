#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct stack_entry
{
    char *data;
    struct stack_entry *next;
};

struct stack_t
{
    struct stack_entry *head;
    size_t stackSize;
};

struct stack_t *
newStack(void)
{
    struct stack_t *stack = malloc(sizeof *stack);
    if (stack)
    {
        stack->head = NULL;
        stack->stackSize = 0;
    }
    return stack;
}

char *copyString(char *str)
{
    char *tmp = malloc(strlen(str) + 1);
    if (tmp)
        strcpy(tmp, str);
    return tmp;
}

void push(struct stack_t *theStack, char *value)
{
    struct stack_entry *entry = malloc(sizeof *entry);
    if (entry)
    {
        entry->data = copyString(value);
        entry->next = theStack->head;
        theStack->head = entry;
        theStack->stackSize++;
    }
}

char *top(struct stack_t *theStack)
{
    if (theStack && theStack->head)
        return theStack->head->data;
    else
        return "NULL\n";
}

void pop(struct stack_t *theStack)
{
    if (theStack->head != NULL)
    {
        struct stack_entry *tmp = theStack->head;
        theStack->head = theStack->head->next;
        free(tmp->data);
        free(tmp);
        theStack->stackSize--;
    }
}

int main()
{
    struct stack_t *theStack = newStack();

    char input[110], command[10];

    while (fgets(input, 110, stdin) != NULL && *input != EOF)
    {
        if (input[0] == 'd')
        {
            printf("%s", top(theStack));
            pop(theStack);
        }

        if (input[0] == 'i')
        {
            int i = 8;

            while (input[i] == ' ')
            {
                i++;
            }

            char *phrase = (input + i);

            push(theStack, phrase);
        }
    }

    return 0;
}
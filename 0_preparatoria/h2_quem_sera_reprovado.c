#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void solve(int n, int inst)
{
    char nome[21], reprovado[21];
    int nota, nota_aux = 11;

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", nome, &nota);

        if (nota < nota_aux)
        {
            nota_aux = nota;
            strcpy(reprovado, nome);
        }

        if (nota == nota_aux && strcmp(nome, reprovado) > 0)
        {
            strcpy(reprovado, nome);
        }
    }
    
    printf("Instancia %d\n%s\n", inst, reprovado);
}

int main()
{
    int n, inst = 1;

    while (scanf("%d", &n) != EOF)
    {
        solve(n, inst);
        inst++;
    }

    return 0;
}
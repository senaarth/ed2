#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *v, int l, int r1, int r2)
{
	int *aux_v = malloc(sizeof(int) * (r2 - l + 1));
	int k = 0;
	int i = l;
	int j = r1 + 1;

	while (i <= r1 && j <= r2)
	{
		if (v[i] < v[j])
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

void merge_sort(int *v, int l, int r)
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
	int *v = malloc(sizeof(int));
	int num, i = 1;

	while (scanf("%d ", &num) != EOF)
	{
		v = realloc(v, i * sizeof(int));
		v[i - 1] = num;
		i++;
	}

	merge_sort(v, 0, i - 2);

	for (int j = 0; j < i - 1; j++)
	{
		printf("%d ", v[j]);
	}

	printf("\n");

	return 0;
}

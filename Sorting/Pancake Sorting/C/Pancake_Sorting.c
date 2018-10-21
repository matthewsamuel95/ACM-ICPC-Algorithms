#include <stdio.h>
#include <stdlib.h>

void flip(int v[], int end, int start);
void pancake_sort(int v[], int end, int start);
int ordenado(int v[], int start, int end);


int main()
{
	int n, i, *v;
	scanf("%d", &n);

	v=malloc(sizeof(int)*n);

	for(i=0;i<n;i++)
		scanf("%d", &v[i]);

	pancake_sort(v, n, 0);

	return 0;

}

void pancake_sort(int v[], int end, int start)
{
	int biggest=start, i;

	if (end>= start)
	{
		for(i=start+1;i<end;i++)
			if (v[i]>v[biggest])
				biggest=i;
		flip(v, end, biggest);
		printf("%d ", biggest);
		flip(v, end, start);
		printf("%d ",start);
	}

	if(!ordenado(v, start, end))
		pancake_sort(v, end, start+1);

}

void flip(int v[], int end, int start)
{
	int aux, i, j;

	for(i=start,j=end-1; i<=j; i++, j--)
	{
		aux=v[i];
		v[i]=v[j];
		v[j]=aux;
	}
}

int ordenado(int v[], int start, int end)
{
	int i;
	for(i=start;i<end;i++)
		if(v[i]<v[i+1]) return 0;

	return 1;
}
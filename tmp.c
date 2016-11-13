#include <stdio.h>

void quick_sort(int array[], int start, int end);
void printArray(int array[], int start, int end);
int main(void)
{
	int num[5] = {4,5,3,2,1};
	quick_sort(num, 0, 4);
	printArray(num, 0, 4);
	return 0;
}

void quick_sort(int array[], int start, int end)
{
	if (start < end)
	{
		int n = quick_sort_loop(array, start, end);
		quick_sort(array, start, n-1);
		quick_sort(array, n+1, end);
	}
}

int quick_sort_loop(int array[], int start, int end)
{
	int i;
	int base = array[start];
	int pos = start;
	int tmp;

	for (i=start+1; i<=end; i++)
	{
		if (array[i]<base && ++pos != i)
		{
			tmp = array[i];
			array[i] = array[pos];
			array[pos] = tmp;	
		}
	}
	array[start] = array[pos];
	array[pos] = base;
	return pos;
}

void printArray(int array[], int start, int end)
{
	int i;
	for(i=start; i<=end; i++)
		printf("%d ", array[i]);
	printf("\n");
}

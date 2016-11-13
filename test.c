#include <stdio.h>

void sort_quick(int array[], int start, int end);
int sort_quick_internal(int array[], int start, int end);
void printArray(int *array, int start, int end);
int main(int argc, char **argv)
{
	int array[5] = {3,4,5,2,1};
	//int array[5] = {1,2,3,4,5};
	printArray(array, 0, 4);
	sort_quick(array, 0,4);
	printArray(array, 0, 4);
	return 0;
}

void sort_quick(int array[], int start, int end)
{
//	printf("out: start %d end %d\n", start, end);
	int p;
	static int loop = 0;
	if (start < end)
	{
		loop++;
	//	printf("loop %d: start %d end %d\n", loop, start, end);
		p = sort_quick_internal(array, start, end);
	//	printf("loop %d: %d\n", p);
		sort_quick(array, start, p-1);
		sort_quick(array, p+1, end);
	}
}

int sort_quick_internal(int array[], int start, int end)
{
//	printf("internal: start %d end %d\n", start, end);
	int base = array[start];
	int lower_p = start;
	int i;
	int tmp;
	for(i = lower_p+1; i<=end; i++)
	{
		if (array[i] < base && ++lower_p != i)
		{
			tmp = array[i];
			array[i] = array[lower_p];
			array[lower_p] = tmp;	
		}
	}
	array[start] = array[lower_p];
	array[lower_p] = base;
	return lower_p;
}

void printArray(int *array, int start, int end)
{
	int i;
	for (i = start; i <= end; i++)
		printf("%d ", array[i]);
	printf("\n");
}

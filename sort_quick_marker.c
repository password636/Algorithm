#include <stdio.h>

#define __DEBUG__ 0
void print_array(int *array, int n);
void sort_quick(int *array, int low, int high);
int sort_quick_internal(int *array, int low, int high);
static int loop = 1;
int
main(int argc, char **argv)
{
	//int array[10] = {4, 6, 7, 9, 10, 1, 3, 5, 8, 2};
	//int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int array[10] = {4, 6, 7, 9, 10, 1, 4, 5, 8, 2};
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	print_array(array, 10);

	sort_quick(array, 0, 9);
	//print_array(array, 10);
	return 0;
}

void sort_quick(int *array, int low, int high)
{
	if (low < high)
	{
		int pos = sort_quick_internal(array, low, high);
		sort_quick(array, low, pos - 1);
		sort_quick(array, pos + 1, high);
	}
}

int sort_quick_internal(int *array, int low, int high)
{
	int pos = low + 1;
	int base = array[low];
	int i;
	int tmp;
	int marker = 0;
	
	for (i=low+1; i<=high; i++)
	{
		if (array[i] > base)
		{
			marker = 1;
		}
		if (array[i] <= base)
		{
			if(marker)
			{
				tmp = array[pos];
				array[pos] = array[i];
				array[i] = tmp;
			}
			pos++;
		}
	}
	array[low] = array[pos-1];
	array[pos-1] = base;
	

#ifdef __DEBUG__
	printf("internal %d:\t", loop++);
	print_array(array, 10);
#endif
	return pos-1;
}

void print_array(int *array, int n)
{
	int i;
	for ( i = 0; i < n; i++ )	
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

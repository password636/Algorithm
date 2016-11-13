#include <stdio.h>

#define __DEBUG__ 0
void print_array(int *array, int n);
void sort_insert(int *array, int start, int end);

static int loop = 1;

int
main(int argc, char **argv)
{
//	int array[10] = {4, 6, 7, 9, 10, 1, 3, 5, 8, 2};
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int array[10] = {4, 6, 7, 9, 10, 1, 4, 5, 8, 2};
//	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	print_array(array, 10);

	sort_insert(array, 0, 9);
	return 0;
}

void 
sort_insert(int *array, int start, int end)
{
	int i;
	int j;
	int object;

	for (i=start+1; i<=end; i++)
	{
		object = array[i];
		for(j=i-1; j>=0 && object < array[j]; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = object;
#ifdef __DEBUG__
	printf("internal %d:\t", loop++);
	print_array(array, 10);
#endif
	}
	
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

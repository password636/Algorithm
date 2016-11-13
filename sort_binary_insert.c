#include <stdio.h>

#define __DEBUG__ 0
void print_array(int *array, int n);
void sort_binary_insert(int *array, int n);
void binary_insert(int *array, int n);

static int loop = 1;

int
main(int argc, char **argv)
{
//	int array[10] = {4, 6, 7, 9, 10, 1, 3, 5, 8, 2};
	//int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int array[10] = {4, 6, 7, 9, 10, 1, 4, 5, 8, 2};
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	print_array(array, 10);

	sort_binary_insert(array, 10);
	//print_array(array, 10);
	return 0;
}

void 
sort_binary_insert(int *array, int n)
{
	int i; 
	for (i=1; i<n; i++)
	{
		binary_insert(array, i);
	}
}

void
binary_insert(int *array, int i)
{
	int left = 0;
	int right = i-1;
	int tmp = array[i];
	int middle;
	int j;

	while (left <= right)
	{
		middle = (left + right) / 2;
		if(tmp < array[middle])
			right = middle-1;
		else
			left = middle+1;
	}

	for(j=i-1; j>=left; j--)
		array[j+1] = array[j];
	array[left] = tmp;

#ifdef __DEBUG__
	printf("internal %d:\t", loop++);
	print_array(array, 10);
#endif
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

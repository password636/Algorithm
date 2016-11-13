#include <stdio.h>

#define __DEBUG__ 0
void print_array(int *array, int n);
void sort_insert(int *array, int start, int end);
void move(int *array, int start, int end);

static int loop = 1;

int
main(int argc, char **argv)
{
//	int array[10] = {4, 6, 7, 9, 10, 1, 3, 5, 8, 2};
//	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	int array[10] = {4, 6, 7, 9, 10, 1, 4, 5, 8, 2};
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	print_array(array, 10);

	sort_insert(array, 0, 9);
	//print_array(array, 10);
	return 0;
}

void 
sort_insert(int *array, int start, int end)
{
	int i;
	int j;

	for (i=start+1; i<=end; i++)
	{
		for(j=i-1; j>=0; j--)
		{
			if (array[i] >= array[j])
			{	
				move(array, j+1, i);
			}
		}
		if (j < 0)	 
		{
			move(array, 0, i);
		}
#ifdef __DEBUG__
	printf("internal %d:\t", loop++);
	print_array(array, 10);
#endif
	}
}

void 
move(int *array, int start, int end)
{
	int tmp = array[end];
	int i;
	for (i=end; i>start; i--)
	{
		array[i] = array[i-1];
	}
	array[start] = tmp;
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

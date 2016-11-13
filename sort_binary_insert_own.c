#include <stdio.h>

#define __DEBUG__ 0
void print_array(int *array, int n);
void sort_binary_insert(int *array, int start, int end);
void move(int *array, int start, int end);

static int loop = 1;

int
main(int argc, char **argv)
{
	//int array[10] = {4, 6, 7, 9, 10, 1, 3, 5, 8, 2};
	//int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//int array[10] = {4, 6, 7, 9, 10, 1, 4, 5, 8, 2};
	int array[10] = {10,9,8,7,6,5,4,3,2,1};
	print_array(array, 10);

	sort_binary_insert(array, 0, 9);
	//print_array(array, 10);
	return 0;
}

void 
sort_binary_insert(int *array, int start, int end)
{
	int i;
	for(i=start+1; i<=end; i++)
	{
		int pos = find(array, start, i-1, i);
		move(array, pos, i);
#ifdef __DEBUG__
	printf("internal %d:\t", loop++);
	print_array(array, 10);
#endif
	}

}

int 
find(int *array, int start, int end, int i)
{
	int pos;
	if (start == end)
	{
		if (array[i]>=array[start])
			return start+1;
		else
			return start;
		
	}
	else if (start > end)
	{
		return start;
	}
	else
	{

		pos = (start+end)/2;
	
		if (array[i] >= array[pos])
			find(array, pos+1, end, i);
		else
			find(array, start, pos-1, i);
	}
}
/*
 * move from start to end. end move to start, i <- i-1.
 */
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

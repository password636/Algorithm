#include <stdio.h>

void print_array(int *array, int n);
void sort_bubble(int *array, int n);
int
main(int argc, char **argv)
{
	int array[10] = {4, 6, 7, 9, 10, 1, 3, 5, 8, 2};
	//int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	print_array(array, 10);

	sort_bubble(array, 10);
	//print_array(array, 10);
	return 0;
}

void sort_bubble(int *array, int n)
{
	int exchange = 1;
	int i, j;
	int tmp;
	
	for (j = 1; j < n && exchange; j++)
	{
		exchange = 0;
		for(i = 0; i < n - j; i++)
		{
			if (array[i]>array[i+1])
			{
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				exchange = 1;
			}
		}
#ifdef __DEBUG__
		printf("loop %d:\t echange == %d\t", j, exchange);
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

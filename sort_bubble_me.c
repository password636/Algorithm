#include <stdio.h>

void sort_bubble(int array[], int n)
{
	int i;
	int j;
	int exchange = 1;
	int temp;
	
	for (i = 0; i < n && exchange == 1; i++)// tang
	{
		printf("loop %d\n", i);	
		exchange = 0;
		for (j = 0; j < n-i; j++) // liang liang bi jiao	
		{
			if (array[j]>array[j+1])
			{		
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
				exchange = 1;
			}
		}
	}
}

void printarray(int array[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	//int array[5] = {4,5,3,1,2};
	int array[5] = {1,2,3,4,5};
	printarray(array, 5);
	sort_bubble(array, 5);
	printarray(array, 5);
	return 0;
}

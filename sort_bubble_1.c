#include <stdio.h>
//#define __DEBUG__ 0

void printArray(int array[], int n);
void sort_bubble(int array[], int n);
int main(void)
{
	//int n[5] = {4,5,2,3,1};
	//int n[5] = {1,2,3,4,5};
	int n[5] = {5,4,3,2,1};
	printArray(n, 5);
	sort_bubble(n, 5);
	printArray(n, 5);
	return 0;
}

void printArray(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)	
		printf("%d ", array[i]);
	printf("\n");
}

void sort_bubble(int array[], int n)
{
	int change = 1;
	int j;
	int i;
	int temp;

	for(i = 1; i < n && change == 1; i++) // i:1->n-1
	{
		change = 0;
		for(j = 0; j < n - i; j++)	// j:0->n-i-1
		{
			if(  array[j] > array[j+1] )
			{
				temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
				change = 1;
			} 
		}
#ifdef __DEBUG__
		printf("debug: ");
		printArray(array, 5);
#endif
	}
}

#include <stdio.h>

void printArray(int array[], int n);
void sort_quick(int array[], int low, int high);
int main(void)
{
	int array[] = {3,4,2,5,1};
	printArray(array, 5);
	sort_quick(array, 0, 4);
	printArray(array, 5);
}

void printArray(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)	
		printf("%d ", array[i]);
	printf("\n");
}

void sort_quick(int array[], int low, int high)
{
	int pos;
	if(low < high)
	{
		pos = sort_quick_internal(array, low, high);
		sort_quick(array, low, pos-1);
		sort_quick(array, pos+1, high);
	}
}

int sort_quick_internal(int array[], int low, int high)
{
	int last_pos = low;
	int temp;
	int base = array[low];
	int i;
	for(i = low+1; i <=high; i++)
	{
		if (base > array[i] && ++last_pos != i)
		{
			temp = array[i];
			array[i] = array[last_pos];
			array[last_pos] = temp;
		}
	}
	array[low] = array[last_pos];
	array[last_pos] = base;
	printArray(array, 5);
	return last_pos;
}

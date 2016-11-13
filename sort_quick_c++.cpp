#include <iostream>
using namespace std;

class sort
{
protected:
	int base;
	int pos;
	int last_pos;
	int temp;
public:
	virtual void sort_quick(int array[], int low, int high) = 0;
	virtual int sort_quick_internal(int array[], int low, int high) = 0;
	void printArray(int array[], int n);
};
void sort::printArray(int array[], int n)
{
	int i;
	for (i = 0; i < n; i++)	
		cout << array[i] << " " ;
	cout << endl;
}

class sort_no_marker: public sort
{
	int sort_quick_internal(int array[], int low, int high);
	void sort_quick(int array[], int low, int high);
};

class sort_marker: public sort
{
	void sort_quick(int array[], int low, int high);
};

int sort_no_marker::sort_quick_internal(int array[], int low, int high)
{
	cout << "sort_no_marker::sort_quick_internal: " << low << " to " << high << endl;
	base = array[low];
	last_pos = low;
	int i;

	for(i = low+1; i<=high; i++)
	{
		if (base>array[i] && ++last_pos != i)
		{
			temp = array[i];
			array[i] = array[last_pos];
			array[last_pos] = temp;
		}
	}
	array[low] = array[last_pos];
	array[last_pos] = base;
	cout << "sort_no_marker::sort_quick_internal: ";
	printArray(array, high-low+1);
	return last_pos;
}
void sort_no_marker::sort_quick(int array[], int low, int high)
{
	cout << "sort_no_marker::sort_quick: " << low << " to " << high << endl;
	if(low < high)	
	{
		pos = sort_quick_internal(array, low, high);
		sort_quick(array, low, pos-1);
		sort_quick(array, pos+1, high);
	}
}

int main(void)
{
	int array[] = {3,4,5,2,1};
	sort *ps;
	sort_no_marker snm;
	ps = &snm;
	ps->printArray(array, 5);
	ps->sort_quick(array, 0, 4);
	ps->printArray(array, 5);
	return 0;
}

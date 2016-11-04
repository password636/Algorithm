#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int n = atoi(argv[1]);
	int i = 1, result = i;
	while ( i < n )
	{
		result *= ++i;
	}
	printf("%d\n", result);
	return 0;
}

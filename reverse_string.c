#include <stdio.h>
#include <string.h>
void reverse_prt(char *s);

int
main(int argc, char **argv)
{
	char *str = argv[1];
	reverse_prt(str);
	return 0;
}

void reverse_prt(char *s)
{
	int length = strlen(s);
	while (*s++ != '\0')
		;
	s--;
	int i;
	for (i = 0; i < length; i++)
	{
		printf("%c", *--s);
	}
}

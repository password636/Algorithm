#include <stdio.h>
void reverse_prt(const char *s);

int main(int argc, char **argv)
{
	char *str = argv[1];
	reverse_prt(str);
	return 0;
}

void reverse_prt(const char *s)
{
	if (*s != '\0')
	{
		reverse_prt(s+1);
		printf("%c", *s);
	}
}

#include <stdio.h>

void mystrcpy(char target[], char source[])
{
	//assert target and source is not NULL
	while( '\0' != (*target++ = *source++) )
		;
}

int main(int argc, char **argv)
{
	char t[100];
	mystrcpy(t, argv[1]);
	printf("%s\n", t);
	return 0;
}

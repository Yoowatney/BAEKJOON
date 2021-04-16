#include <string.h>
#include <stdio.h>

int main()
{
	char s[20] = "abc";
	char ss[20] = "abcd";
	ss[3] = '\0';
	printf("%d", strcmp(s,ss));
}

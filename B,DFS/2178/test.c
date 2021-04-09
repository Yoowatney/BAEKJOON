#include <stdio.h>
#include <stdlib.h>

typedef struct _test_t 
{
	int x;
	int y;
} test_t;
int main()
{
	test_t test[1];

	int i = 0;
	while (test[i] != NULL)
	{
		printf("%d %d\n", test[i].x, test[i].y);
		i++;
	}
}

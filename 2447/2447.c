#include <stdio.h>

void star(int x, int y, int num)
{ 
	if ((x / num) % 3 == 1 && (y / num) % 3 == 1) 
	   	printf(" ");
	else 
	{ 
		if (num / 3 == 0) 
			printf("*"); 
		else
			star(x, y, num / 3);
	} 
}
int main(void) 
{
   	int num;

   	scanf("%d", &num);
   	for (int x = 0; x < num; ++x) 
	{ 
		for (int y = 0; y < num; ++y) 
		   	star(x, y, num);
	   	printf("\n");
   	}
   	return (0); 
}


#include <stdio.h>


int main()
{
	int arr[2][5];

	printf("arr[0][4] : %p\n", &arr[0][4]);
	printf("arr[0][4] : %p\n", &arr[0][4] + 1);

	printf("arr[1][0] : %p\n", &arr[1][0]);
}

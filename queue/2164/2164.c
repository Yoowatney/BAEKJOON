#include <stdio.h>

int arr[1000000];

int main()
{
	int size;
	int front = 0;
	int temp;

	scanf("%d", &size);
	int rear = size;
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1;
	}
	while (front < rear - 1)
	{
		arr[front] = 0;
		front++;
		arr[rear] = arr[front];
		front++;
		rear++;
		for (int i = front; i < rear; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	printf("answer : %d\n", arr[front]);
}

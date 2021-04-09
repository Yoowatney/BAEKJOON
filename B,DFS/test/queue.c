#include <stdio.h>
#define max 100
int front = -1;
int rear = -1;
int queue[max];

int isempty()
{
	if (front == rear)
		return (1);
	else
		return (0);
}

int isfull()
{
	int temp = (rear + 1) % max;
	if (temp == front)
		return (1);
	else
		return (0);
}

void	addq(int value)
{
	if (isfull())
		printf("Queue is full\n");
	else
	{
		rear = (rear + 1) % max;
		queue[rear] = value;
	}
	return ;
}

int		deleteq()
{
	if (isempty())
		printf("Queue is empty\n");
	else
	{
		front = (front + 1) % max;
		return (queue[front]);
	}
}

int main()
{
	addq(4);
	addq(7);
	addq(12);
	printf("%d\n", deleteq());
	printf("%d\n", deleteq());
	printf("%d\n", deleteq());
	deleteq();
}

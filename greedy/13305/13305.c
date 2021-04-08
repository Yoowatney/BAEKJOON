#include <stdio.h>

int main()
{
	int size;

	scanf("%d", &size);
	long long distance[size - 1];
	long long gasStation[size];
	long long result = 0;
	long long min;

	for (int i = 0; i < size - 1; i++)
		scanf("%lld", &distance[i]);
	for (int i = 0; i < size; i++)
		scanf("%lld", &gasStation[i]);
	min = gasStation[0];
	for (int i = 0; i < size - 1; i++)
	{
		if (min > gasStation[i])
			min = gasStation[i];
		result += min * distance[i];
	}
	printf("%lld\n", result);
}

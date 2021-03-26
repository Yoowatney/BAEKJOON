#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
	int x;
	int y;
} coordinates;

//struct coordinates
//{
//	int x;
//	int y;
//}

coordinates sort[100001];

void merge(coordinates *arr, int first, int mid, int last)
{
	int i, j, k;
	i = first;
	j = mid + 1;
	k = first;

	while (i <= mid && j <= last) {
		if (arr[i].x < arr[j].x)
			sort[k++] = arr[i++];
		else if (arr[i].x > arr[j].x)
			sort[k++] = arr[j++];
		else {
			if (arr[i].y < arr[j].y)
				sort[k++] = arr[i++];
			else if (arr[i].y > arr[j].y)
				sort[k++] = arr[j++];
		}
	}

	if (i <= mid) {
		while (i <= mid) 
			sort[k++] = arr[i++];
	}
	else {
		while (j <= last) 
			sort[k++] = arr[j++];
	}
	for (k = first; k <= last; k++)
		arr[k] = sort[k];
}

void mergesort(coordinates *arr, int first, int last) {
	int mid;
	if (first < last) {
		mid = (first + last) / 2;
		mergesort(arr, first, mid);
		mergesort(arr, mid + 1, last);
		merge(arr, first, mid, last);
	}
}

int main(void)
{
	int size;
	scanf("%d", &size);
	coordinates arr[size];
//	coordinates *arr = (coordinates *)malloc(sizeof(coordinates) * size);
	for(int i = 0; i < size; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	mergesort(arr, 0, size - 1);
	for (int i = 0; i < size; i++)
		printf("%d %d\n", arr[i].x, arr[i].y);

	return 0;
}

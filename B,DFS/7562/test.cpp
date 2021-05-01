#include <bits/stdc++.h>

using namespace std;

int main()
{
	queue <pair <int, int>> q;
	q.push(make_pair(1,2));
	queue <int> Q;
	Q.push(3);
	//cout << Q.front();
	int arr[5];
	fill(arr + 1, arr + 4, 1);
	for (int e : arr)
	{
		cout << e << ' ';
	}
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
	queue <pair <int, int> > q;
	pair <int, int> r = make_pair(0,0);
	q.push(r);
	cout << q.front().first;
}

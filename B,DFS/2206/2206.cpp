#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int arr[1000][1000];
int visited[1000][1000][2];

int BFS();

int main()
{
	scanf("%d %d", &n, &m);
//	int arr[n][m];
//	int visited[n][m];
	for (int i = 0; i < n; i++)
	{
		std::fill(arr[i], arr[i] + m, -1);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	cout << BFS();
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << visited[i][j][1] << ' ';
//		}
//		cout << '\n';
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << visited[i][j][0] << ' ';
//		}
//		cout << '\n';
//	}
}

int	BFS()
{
	queue< tuple <int, int, int> > q;
	tuple <int, int, int> r = make_tuple(0, 0, 0);
	q.push(r);
	int pop_x;
	int pop_y;
	int nx;
	int ny;
	int crashed;

//int dx[] = {-1, 1, 0, 0};
//int dy[] = {0, 0, -1, 1};
	while (!q.empty())
	{
		tie(pop_y, pop_x, crashed) = q.front();
		q.pop();
		if (pop_y == n - 1 && pop_x == m -  1)
		{
			return (visited[pop_y][pop_x][crashed] + 1);
			break ;
		}
		for (int i = 0; i < 4; i++)
		{
			ny = dy[i] + pop_y;
			nx = dx[i] + pop_x;
			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue ;
			if (visited[ny][nx][crashed] || arr[ny][nx] == -1)
				continue ;
			if (arr[ny][nx] == 0)
			{
				q.push(make_tuple(ny, nx, crashed));
				visited[ny][nx][crashed] = visited[pop_y][pop_x][crashed] + 1;
			}
			if (arr[ny][nx] == 1)
			{
				if (crashed == 1)
					continue ;
				visited[ny][nx][crashed + 1] = visited[pop_y][pop_x][crashed] + 1;
				q.push(make_tuple(ny, nx, crashed + 1));
			}
		}
	}
	return (-1);
}

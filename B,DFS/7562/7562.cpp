#include <bits/stdc++.h>

using namespace std;

typedef struct Queue 
{
	int x;
	int y;	
} Queue;

int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int l;

void	bfs(vector<vector<int>> visited, int x, int y, int now_x, int now_y)

{
	int front = 0;
	int rear = 0;
	Queue queue[100000];
	memset(queue, 0 ,sizeof(queue));
	int pop_x, pop_y;
	visited[now_y][now_x] = 1; // pos 확인
	queue[rear].x = now_x;
	queue[rear].y = now_y;
	rear++;

	int nx;
	int ny;
	int num = 0;
	int g[l][l];
	g[now_y][now_x] = num;

	memset(g, 0, sizeof(g));
	while (front < rear)
	{
		pop_x = queue[front].x;
		pop_y = queue[front].y;
		front++;
		num++;
		for (int i = 0; i < 8; i++)
		{
			nx = pop_x + dx[i];
			ny = pop_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l)
				continue ;
			if (visited[ny][nx] == 1)
				continue ;
			g[ny][nx] = g[pop_y][pop_x] + 1;
			visited[ny][nx] = 1;
			queue[rear].x = nx;
			queue[rear].y = ny;
			rear++;
		}
	}
	cout << g[y][x] << '\n';
//	cout << '\n' << "--- start ---" << '\n';  
//	for (int i = 0; i < l; i++)
//	{
//		for (int j = 0; j < l; j++)
//		{
//			cout << g[i][j] << ' ';
//		}
//		cout << '\n';
//	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	int now_x, now_y;
	int x, y;
	for (int i = 0; i < t; i++)
	{
		cin >> l;
		vector<vector<int>> visited(l, vector<int>(l,0));
		cin >> now_x >> now_y >> x >> y;
		bfs(visited, x, y, now_x, now_y);
	}
}


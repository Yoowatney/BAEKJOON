#include <stdio.h>
#define N 7
 
int g[N][N]=
{
    {0,1,0,0,0,1,1},
    {1,0,1,1,0,0,0},
    {0,1,0,0,1,0,0}, 
    {0,1,0,0,0,0,0},
    {0,0,1,0,0,0,0},
    {1,0,0,0,0,0,1},
    {1,0,0,0,0,1,0}
};

int visited[N];

void dfs(int here)
{
    //지금 here이 이미 방문된 정점이라면 다시 빠꾸
    if (visited[here])
		return;
 
    printf("정점 %d를 방문\n", here);

    visited[here] = 1;  //지금 here 정점은 방문

    for (int next = 0; next < N; next++) 
        //그래프가 이어져있으면서, 아직 다음 정점이 방문되지 않았으면 ㄱㄱ
        if (g[here][next] == 1 && !visited[next])
			dfs(next);
}

int main()
{
    dfs(0);
}

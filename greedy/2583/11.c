#include <stdio.h>
 
int arr[100][100];
int result[100];
int M, N, K;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
 
//깊이 우선 탐색
//value값을 삽입
int dfs(int x, int y, int value) {
    arr[x][y] = value;
 
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if (nx >= 0 && ny >= 0 && nx < M && ny < N && arr[nx][ny] == 0)
            dfs(nx, ny, value);
    }
    return 0;
}
 
int main() {
    scanf("%d %d %d", &M, &N, &K);
	int a, b;
	int c, d;

	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &a, &b);
		scanf("%d %d", &c, &d);
		for (int y_temp = b; y_temp <= d; y_temp++)
		{
			for (int x_temp = a; x_temp <= c; x_temp++)
			{
				arr[y_temp][x_temp] = 1;
			}
		}
	}

    //영역 검사하기
    int cnt = 1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 0)
			{
                cnt++;
                dfs(i, j, cnt);
            }
        }
    }
 
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
		{
            result[arr[i][j]]++;
        }
    }
	int small;
	for (int i = 2; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (result[i] > result[j])
			{
				small = result[j];
				result[j] = result[i];
				result[i] = small;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		printf("temp[%d] : %d\n", i, result[i]);
	}

 
//    sort(result + 2, result + cnt + 1);
    printf("%d\n", cnt - 1);
//    for (int i = 2; i <= cnt; i++)
//        printf("%d ", result[i]);
    printf("\n");
 
    return 0;
}


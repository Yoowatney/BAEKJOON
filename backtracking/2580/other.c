#include <stdio.h>
#include <stdbool.h>

int arr[10][10] = {0,};	//스도쿠배열
int zeroArr[100][2] = {0,};	//0인배열 행,열 저장하는 배열
int cnt = 0;	//0의 갯수 카운트
bool isSolve = false;	//스도쿠가 풀림여부

//필요한 탐색인가? 
bool isPromising(int row, int col, int num)
{
	//행으로 유효한가?
	for (int i = 0; i < 9; i++)
	{
		if (arr[row][i] == num) 
			return false;
	}

	//열으로 유효한가?
	for (int i = 0; i < 9; i++)
	{
		if (arr[i][col] == num)
			return false;
	}

	//작은 상자가 유효한가?
	for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++)
	{
		for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++)
		{
			if (arr[i][j] == num) 
				return false;
		}
	}
	return true;
}

//스도쿠 출력
void printData()
{
	if (!isSolve)
	{
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	return ;
}
//백트래킹
void	backtracking(int index)
{
	//1~9까지경우의 수 탐색
	for (int j = 1; j <= 9; j++)
	{
		//유효하면
		if (isPromising(zeroArr[index][0], zeroArr[index][1], j))
		{
			arr[zeroArr[index][0]][zeroArr[index][1]] = j;	//대입 
			//스도쿠가 완성되면 출력
			if (index + 1 == cnt)
			{
				printData();
				isSolve = true;
				return;
			}
			backtracking(index + 1);	//백트래킹
			arr[zeroArr[index][0]][zeroArr[index][1]] = 0;	
			//돌아왔다면 다시 0으로
		}
	}
}


int main()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++){
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)
			{//0인 row와 col저장
				zeroArr[cnt][0] = i;
				zeroArr[cnt][1] = j;
				cnt++;
			}
		}
	}
	backtracking(0);
	if(!isSolve)
		printf("Not Possible");
	return 0;
}

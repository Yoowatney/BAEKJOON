#include <stdio.h>

typedef struct __score 
{
	int x;
	int y;
} _score;

int main()
{
	int T;
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int num;
		int cnt = 0;
		scanf("%d", &num);
		_score score[num];
	
		int doc_first[2];
		int inter_first[2];
		for (int i = 0; i < num; i++)
		{
			scanf("%d %d", &score[i].x, &score[i].y);
			if (score[i].x == 1)
			{
				doc_first[0] = score[i].x;
				doc_first[1] = score[i].y;
			}
			if (score[i].y == 1)
			{
				inter_first[0] = score[i].x;
				inter_first[1] = score[i].y;
			}
		}
//		printf("doc : %d %d, inter : %d %d\n", doc_first[0], doc_first[1], inter_first[0], inter_first[1]);
		for (int i = 0; i < num; i++)
		{
//			if (doc_first[0] == inter_first[0] && doc_first[1] == inter_first[1])
//			{
//				printf("위에서 선택된 score %d %d\n", doc_first[0], doc_first[1]);
//				cnt++;
//			}
			if (doc_first[1] >= score[i].y && inter_first[0] >= score[i].x)			
			{
				printf("선택된 score : %d %d\n", score[i].x, score[i].y);
				cnt++;
			}
		}
		printf("cnt : %d\n", cnt);
	}
}


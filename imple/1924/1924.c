#include <stdio.h>
#include <string.h>
int main()
{
	int month, day;
	scanf("%d %d", &month, &day);
	char days[7][4];

	strcpy(days[0], "SUN");
	strcpy(days[1], "MON");
	strcpy(days[2], "TUE");
	strcpy(days[3], "WED");
	strcpy(days[4], "THU");
	strcpy(days[5], "FRI");
	strcpy(days[6], "SAT");
	if (month == 1)
	{
		for (int i = 0; i < 7; i++)
		{
			if (day % 7 == i)
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 2)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 3) % 7 == i)
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 3)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 3) % 7 == i)
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 4)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 6) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 5)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 1) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 6)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 4) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 7)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 6) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 8)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 2) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 9)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 5) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 10)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 11)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day + 3) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
	else if (month == 12)
	{
		for (int i = 0; i < 7; i++)
		{
			if ((day) % 7 == i) 
			{
				printf("%s\n", days[i]);
			}
		}
	}
}

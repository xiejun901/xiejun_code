#include<stdio.h>
#define AN 100000
int solve(int *a, int *b, int n, int start);
int main()
{
	int task;
	int n;
	int a[AN];
	int b1[AN];
	int b2[AN];
	int yesTable[AN];
	int noTable[AN];
	int i, temp1, temp2;
	int yesCount, noCount;
	scanf("%d", &task);
	while (task--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		temp1 = solve(a, b1, n, 0);
		temp2 = solve(a, b2, n, 1);
		if ((temp1 == 1) && (temp2 == 1))
		{
			yesCount = 0;
			noCount = 0;
			for (i = 0; i < n; i++)
			{
				if (b1[i] == b2[i])
				{
					if (b1[i] == 1)
					{
						yesTable[yesCount] = i + 1;
						yesCount++;
					}
					else
					{
						noTable[noCount] = i + 1;
						noCount++;
					}
				}
			}
		}
		else if (temp1 == 1)
		{
			yesCount = 0;
			noCount = 0;
			for (i = 0; i < n; i++)
			{
				if (b1[i] == 1)
				{
					yesTable[yesCount] = i + 1;
					yesCount++;
				}
				else
				{
					noTable[noCount] = i + 1;
					noCount++;
				}
			}
		}
		else if (temp2 == 1)
		{
			yesCount = 0;
			noCount = 0;
			for (i = 0; i < n; i++)
			{
				if (b2[i] == 1)
				{
					yesTable[yesCount] = i + 1;
					yesCount++;
				}
				else
				{
					noTable[noCount] = i + 1;
					noCount++;
				}
			}
		}
		printf("%d ", yesCount);
		for (i = 0; i < yesCount; i++)
			printf("%d ", yesTable[i]);
		printf("\n");
		printf("%d ", noCount);
		for (i = 0; i < noCount; i++)
			printf("%d ", noTable[i]);
		printf("\n");
	}
}

int solve(int *a, int *b, int n, int start)
{
	int i;
	b[0] = start;
	if (n == 1)
	{
		if (a[0] == b[0])
			return 1;
		else
			return 0;
	}
	b[1] = a[0] - b[0];
	if ((b[1] <0 || b[1] > 1))
		return 0;
	if (n == 2)
	{
		if ((a[1] == b[0] + b[1]))
			return 1;
		else
			return 0;
	}
	i = 2;
	while (i < n)
	{
		b[i] = a[i - 1] - b[i - 1] - b[i - 2];
		if (b[i]<0 || b[i]>1)
			return 0;
		i++;
	}
	if (a[n - 1] == b[n - 1] + b[n - 2])
		return 1;
	else
		return 0;

}
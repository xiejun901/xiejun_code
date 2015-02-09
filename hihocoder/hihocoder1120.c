#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define M 10
void enumbin(int *b, int i, int j);
int isRight(void);
int caculateBomb(int indexi, int indexj);
int b[N*M] = {  0, 0, 1, 2, -1, 1 ,  1, 1, 1 ,- 1, 2, 1 , -1, 1, 1, 1, 1, 0  };
int a[N][M] = { { 0, 0, 1, 2, -1, 1 }, { 1, 1, 1 ,- 1, 2, 1 }, { -1, 1, 1, 1, 1, 0 } };
int c[N*M] = { 0 };
int cnt = 0;
int m = 6;
int n = 3;
int main()
{
	int task;
	scanf("%d",&task);
	int i, j;
	int yesCount, noCount;
	while (task--)
	{
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
			}
		}
		memset(b, -1, N*M*sizeof(int));
		memset(c, 0, N*M*sizeof(int));
		cnt = 0;
		yesCount = 0;
		noCount = 0;
		enumbin(b, 0, m*n - 1);
		for (i = 0; i < m*n; i++)
		{
			if (c[i] == cnt)
				yesCount++;
			else if (c[i] == 0)
				noCount++;
		}
		printf("%d %d\n", yesCount, noCount);
	}
	return 0;
}

void enumbin(int *b, int i, int j)
{
	int temp;
	int k;
	while (a[j/m][j%m] != -1 && i <= j)
		j--;
	if (i <=j)
	{
		*( b+ j) = 0;
		enumbin(b, i, j - 1);
		*(b + j) = 1;
		enumbin(b, i, j - 1);
	}
	else
	{
		//for (k = 0; k < m*n; k++)
		//	printf("%d ", *(b + k));
	//	printf("\n");
		temp = isRight();
		//printf("%    d\n", temp);
		if (temp == 1)
		{
			for (i = 0; i < m*n; i++)
			{
				c[i] = c[i] + b[i];
			}
			cnt++;
		}
	}
}


int isRight(void)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] != -1)
			{
				if (a[i][j] != caculateBomb(i, j))
					return 0;
			}
		}
	}
	return 1;
}

int caculateBomb(int indexi, int indexj)
{
	int i, j;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		if (((indexi + i) < 0) || ((indexi + i) >= n))
			continue;
		for (j = -1; j <= 1; j++)
		{
			if (((indexj + j) < 0) || ((indexj + j) >= m) || (i == 0 && j == 0))
				continue;
			if (a[indexi + i][indexj + j] == -1 && b[(indexi + i)*m + indexj + j]==1)
			{
				count++;
			}
		}
	}
	return count;
}

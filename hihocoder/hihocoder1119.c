#include<stdio.h>
#define N 200
#define M 200
int find1(int a[N][M], int b[N][M], int indexi, int indexj);
void find2(int a[N][M], int b[N][M], int indexi, int indexj);
void find3(int a[N][M], int b[N][M], int indexi, int indexj);
int caculateUnknow(int a[N][M], int indexi, int indexj);
int isAdjacent(int i1, int j1, int i2, int j2);
int isIn(int a[N][M], int i1, int j1, int i2, int j2);
int m, n;
int main()
{
	int task;
	int  i, j;
	int a[N][M];
	int b[N][M];
	int yesCount;
	int noCount;
	scanf("%d", &task);
	while (task--)
	{
		yesCount = 0;
		noCount = 0;
		scanf("%d", &n);
		scanf("%d", &m);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &a[i][j]);
				b[i][j] = -1;
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (a[i][j] == 0)
					find1(a, b, i, j);
				if (a[i][j]>0)
				{
					find2(a, b, i, j);
					find3(a, b, i, j);
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (b[i][j] == 0)
					yesCount++;
				else if (b[i][j] == 1)
					noCount++;
			}
		}
		printf("%d %d\n", noCount, yesCount);

	}
	return 0;
}
//���õ�һ�ֹ���ȷ��Ϊ0��λ�õ���Χδ̽����λ�ö����޵��׵�
int find1(int a[N][M], int b[N][M], int indexi, int indexj)
{
	int i, j;
	for (i = -1; i <= 1; i++)
	{
		if (((indexi + i) < 0) || ((indexi + i) >= n))
			continue;
		for (j = -1; j <= 1; j++)
		{
			if (((indexj + j) < 0) || ((indexj + j) >= m) || (i == 0 && j == 0))
				continue;
			if (a[indexi + i][indexj + j] == -1)
			{
				b[indexi + i][indexj + j] = 0;
			}
		}
	}
	return 0;
}
//���õڶ��ֹ������ĳλ�õ���Χ��δ̽�����������ڵ�ǰ��������֣���δ̽���ķ����ﶼ�����׵�
void find2(int a[N][M], int b[N][M], int indexi, int indexj)
{
	int i, j;
	int count = 0;
	count = caculateUnknow(a,indexi,indexj);
	if (count == a[indexi][indexj])
	{
		for (i = -1; i <= 1; i++)
		{
			if (((indexi + i) < 0) || ((indexi + i) >= n))
				continue;
			for (j = -1; j <= 1; j++)
			{
				if (((indexj + j) < 0) || ((indexj + j) >= m) || (i == 0 && j == 0))
					continue;
				if (a[indexi + i][indexj + j] == -1)
				{
					b[indexi + i][indexj + j] = 1;
				}
			}
		}

	}
}
//���õ����ֹ����ж��������������A,B�����A��Χδ̽���ĸ��Ӽ���ΪS_A��B��Χδ̽��
//�ĸ��Ӽ���ΪS_B�����S_A����S_B����A�е����ּ�ȥB�е����ֵ���S_A-SB����������SA-SB���ǵ���
void find3(int a[N][M], int b[N][M], int indexi, int indexj)
{
	int i, j;
	int i2, j2;
	int count = 0;
	int diff;
	for (i = -2; i <= 2; i++)
	{
		if (((indexi + i) < 0) || ((indexi + i) >= n))
			continue;
		for (j = -2; j <= 2; j++)
		{
			if (((indexj + j) < 0) || ((indexj + j) >= m) || (i==0 && j==0))
				continue;
			if (a[indexi + i][indexj + j]>=0 && isIn(a, indexi + i, indexj + j, indexi, indexj))
			{
				diff = caculateUnknow(a, indexi, indexj)- caculateUnknow(a, indexi + i, indexj + j);
				if (diff == a[indexi][indexj]-a[indexi + i][indexj + j])
				{
					for (i2 = -1; i2 <= 1; i2++)
					{
						if (((indexi + i2) < 0) || ((indexi + i2) >= n))
							continue;
						for (j2 = -1; j2 <= 1; j2++)
						{
							if (((indexj + j2) < 0) || ((indexj + j2) >= m) || (i2 == 0 && j2 == 0))
								continue;
							if ((a[indexi + i2][indexj + j2] == -1) && (!isAdjacent( indexi + i2, indexj + j2, indexi + i, indexj + j)))
							{
								b[indexi + i2][indexj + j2] = 1;
							}
						}
					}
				}
			}
			
		}
	}
}
//�ж��������,���ڷ���1
int isAdjacent(int i1, int j1, int i2, int j2)
{
	if ((i1 - i2) > 1 || (i1 - i2)<-1 || (j1 - j2)>1 || (j1 - j2) < -1)
		return 0;
	else
		return 1;
}
//����ĳ����Χδ̽����������
int caculateUnknow(int a[N][M], int indexi, int indexj)
{
	int i, j;
	int count = 0;
	for (i = -1; i <= 1; i++)
	{
		if (((indexi + i) < 0) || ((indexi + i) >= n))
			continue;
		for (j = -1; j <= 1; j++)
		{
			if (((indexj + j) < 0) || ((indexj + j) >= m) ||(i==0 && j==0))
				continue;
			if (a[indexi + i][indexj + j] == -1)
			{
				count++;
			}
		}
	}
	return count;
}
//�жϵ�1��Χ��δ֪�����Ƿ񱻵�2��Χ�İ���
int isIn(int a[N][M], int i1, int j1, int i2, int j2)
{
	int i, j;
	for (i = -1; i <= 1; i++)
	{
		if (((i1 + i) < 0) || ((i1 + i) >= n))
			continue;
		for (j = -1; j <= 1; j++)
		{
			if (((j1 + j) < 0) || ((j1 + j) >= m) || (i == 0 && j == 0))
				continue;
			if (a[i1 + i][j1 + j] == -1 && (!isAdjacent(i1 + i, j1 + j, i2, j2)))
				return 0;


		}
	}
	return 1;
}
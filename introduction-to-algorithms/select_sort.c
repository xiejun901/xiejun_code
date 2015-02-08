#include <stdio.h>
void select_sort(int *a,int n);
int main(void)
{
	int i,n;
	int a[100];
	srand((unsigned)time(NULL));
	n=rand()%20+1;
	printf("n is :%d\n",n);
	for(i=1;i<=n;i++)
	{
		a[i]=rand()%100;
		printf("%3d ",a[i]);
	}
	printf("\n");
	select_sort(a,n);
	for(i=1;i<=n;i++)
	{
		printf("%3d ",a[i]);
	}
	printf("\n");
	return 0;
}

void select_sort(int *a,int n)
{
	int i,j,temp;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[j]<a[i])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

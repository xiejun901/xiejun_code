#include <stdio.h>
void insert_sort(int *a,int n);
int main()
{
	int i;
	int n;
	int a[101];
	srand((unsigned)time(NULL));
	n=rand()%20+1;
	printf("n:%d\n",n);
	for(i=1;i<=n;i++)
	{
		a[i]=rand()%100;
		printf("%3d ",a[i]);
	}
	printf("\n");
	insert_sort(a,n);
	for(i=1;i<=n;i++)
		printf("%3d ",a[i]);
	printf("\n");
	return 0;
}

void insert_sort(int *a,int n)
{
	int i,j,temp;
	for(i=2;i<=n;i++)
	{
		j=i-1;
		temp=a[i];
		while((j>0)&&(temp<a[j]))
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}

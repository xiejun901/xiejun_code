// 快速排序
#include <stdlib.h>
#include <stdio.h>
void quick_sort(int* a,int p,int r);
int partition(int* a,int p,int r);
int main(void)
{
	int a[100]={0};
	int i=0;
	int n=0;
	srand((unsigned)time(NULL));
	n=rand()%40+1;
	printf("%d\n",n);
	for(i=0;i<n;i++)
		a[i]=rand()%100;
	for(i=0;i<n;i++)
		printf("%d,",a[i]);
	printf("\n");
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d,",a[i]);
	printf("\n");
	return 0;
}

void quick_sort(int* a,int p,int r)
{
	int q=0;
	if(p<r)
	{
		q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}

int partition(int* a,int p,int r)
{
	int i=0;
	int j=0;
	int temp=0;
	i=p;
	for(j=p;j<r;j++)
	{
		if(a[j]<a[r])
		{
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			i++;
		}
	}
	temp=a[r];
	a[r]=a[i];
	a[i]=temp;
	return i;
}

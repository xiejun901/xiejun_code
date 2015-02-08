/********************************************************************************************
递归方式的插入排序
***********************************************************************************************/
#include <stdio.h>
void insert(int *a,int n);
void insert_sort(int * a,int n);
int main()
{
	int i;
	int n;
	int a[100];
	printf("please input n:");
	scanf("%d",&n);
	printf("please input a:");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	insert_sort(a,n);
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
void insert_sort(int * a,int n)
{
	if(n>1)
	{
		insert_sort(a,n-1);
		insert(a,n);
	}
}
void insert(int *a,int n)
{
	int i;
	int temp;
	i=n-1;
	temp=a[n];
	while((i>0)&&(a[i]>temp))
	{
		a[i+1]=a[i];
		i--;
	}
	a[i+1]=temp;
}


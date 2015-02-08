#include <stdio.h>
#define NIL 0
int find(int * a,int n,int v);
int main(void)
{
	int i,n,v;
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
	v=rand()%100;
	printf("v is :%d\n",v);
	printf("the answer is:%d\n",find(a,n,v));
	return 0;
}

int find(int * a,int n,int v)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(a[i]==v)
		{
			return i;
		}
	}
	return NIL;
}

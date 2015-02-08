#include <stdio.h>
#define NIL 0
int find(int * a,int p,int r,int v);
int main(void)
{
	int i,n,v;
	int a[100];
	srand((unsigned)time(NULL));
	n=rand()%20+1;
	printf("n is :%d\n",n);
	a[0]=0;
	for(i=1;i<=n;i++)
	{
		a[i]=2*i+rand()%2+1;
		printf("%3d ",a[i]);
	}
	printf("\n");
	v=rand()%20;
	printf("v is :%d\n",v);
	printf("the answer is:%d,%d\n",find(a,1,n,v),find_iterative(a,1,n,v));
	return 0;
}

int find(int * a,int p,int r,int v)
{
	int q;
	if(p<=r)
	{
		q=(p+r)/2;
		if(a[q]==v)
			return q;
		else if(v<a[q])
			return find(a,p,q-1,v);
		else
			return find(a,q+1,r,v);
	}
	return NIL;
}
int find_iterative(int * a,int p, int r, int v)
{
	int q;
	while(p<=r)
	{
		q=(p+r)/2;
		if(a[q]==v)
			return q;
		else if(v<a[q])
			r=q-1;
		else
			p=q+1;
	}
	return NIL;
}

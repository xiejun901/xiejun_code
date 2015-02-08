#include <stdio.h>
int merge(int * a,int p, int q, int r);
int merge_sort(int * a,int p,int r);
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
	merge_sort(a,1,n);
	for(i=1;i<=n;i++)
	{
		printf("%3d ",a[i]);
	}
	printf("\n");
	return 0;
}

int merge(int * a,int p, int q, int r)
{
	int right[50];
	int left[50];
	int n1;
	int n2;
	n1=q-p+1;
	n2=r-q;
	int i,j,k;
	for(i=1;i<=n1;i++)
		left[i]=a[p+i-1];
	left[i]=65535;
	for(j=1;j<=n2;j++)
		right[j]=a[q+j];
	right[j]=65535;
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
	}
}
int merge_sort(int * a,int p,int r)
{
	int q;
	if(p<r)
	{
		q=(r+p)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

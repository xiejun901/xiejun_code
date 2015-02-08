#include <stdio.h>
void max_heapfy(int * a,int length,int i);
void build_max_heap(int * a, int heap_size);
void heap_sort(int* a,int length);
void max_heap_insert(int* a,int heaplen,int x);
void heap_increase_key(int *a,int heaplen,int i,int x);
int heap_extract_max(int *a,int heaplen);
int heap_maxinum(int *a);
int main(void)
{
	int i;
	int temp;
	int a[15]={0,5,13,2,25,7,17,20,8,4};
	int length=9;
	build_max_heap(a,length);
	for(i=1;i<=length;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
	temp=heap_maxinum(a);
	printf("%d\n",temp);
	temp=heap_extract_max(a,length);
	printf("%d\n",temp);
	for(i=1;i<=length-1;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
	heap_increase_key(a,length-1,5,25);
	for(i=1;i<=length-1;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
	max_heap_insert(a,length-1,13);
	for(i=1;i<=length;i++)
	{
		printf("%d,",a[i]);
	}
	printf("\n");
	return 0;

}

void max_heapfy(int * a,int length,int i)
{
	int l=i*2;
	int r=i*2+1;
	int largest;
	int temp;
	if(l<=length && a[l]>a[i])
		largest=l;
	else
		largest=i;
	if(r<=length && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		max_heapfy(a,length,largest);
	}
}

void build_max_heap(int * a, int heap_size)
{
	int i;
	for(i=heap_size/2;i>=1;i--)
	{
		max_heapfy(a,heap_size,i);
	}
}

void heap_sort(int* a,int length)
{
	int temp;
	int i;
	build_max_heap(a,length);
	for(i=length;i>1;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		max_heapfy(a,i-1,1);
	}
}
//返回堆中最大值
int heap_maxinum(int *a)
{
	return a[1];
}

int heap_extract_max(int *a,int heaplen)
{
	int temp;
	temp=a[1];
	a[1]=a[heaplen];
	heaplen--;
	max_heapfy(a,heaplen,1);
	return temp;
}

void heap_increase_key(int *a,int heaplen,int i,int x)
{
	int temp;
	if(a[i]>x)
		printf("new key is smaller than current key");
	a[i]=x;
	while(i>1&&a[i/2]<a[i])
	{
		temp=a[i/2];
		a[i/2]=a[i];
		a[i]=temp;
		i=i/2;
	}
}

void max_heap_insert(int* a,int heaplen,int x)
{
	heaplen=heaplen+1;
	a[heaplen]=-1000;
	heap_increase_key(a,heaplen,heaplen,x);
}

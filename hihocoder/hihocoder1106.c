#include<stdio.h>
int sovleGeneration(int order, int gen);
int main()
{
	int t;
	int order, gen;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &order, &gen);
		printf("%d\n", sovleGeneration(order, gen));
	}
	return 0;
}

int sovleGeneration(int order, int gen)
{
	order = order - 1;
	while (gen && (order % 4 != 1) && (order % 4 != 2))
	{
		order = order / 4;
		gen--;
	}
	return gen;
}
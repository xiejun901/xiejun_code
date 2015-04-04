//这道题要注意讨论一下a，b，c为0的情况
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double xp, yp;
double a, b, c;
double high, low;
void getRange()
{
	double bound1, bound2;
	double temp = b*b - 4 * a*(c - yp);
	if (a == 0 && b == 0)
	{
		bound1 = xp;
	}
	else if (a == 0)
	{
		bound1 = (yp - c) / b;
	}
	else
	{
		if (temp > 0)
		{
			double x1 = (-1 * b + sqrt(temp)) / (2 * a);
			double x2 = (-1 * b - sqrt(temp)) / (2 * a);
			bound1 = abs(x1 - xp) < abs(x2 - xp) ? x1 : x2;
		}
		else
		{
			bound1 = -b / 2 / a;
		}
	}
	bound2 = xp;
	if (bound1>bound2)
	{
		low = bound2;
		high = bound1;
	}
	else
	{
		low = bound1;
		high = bound2;
	}
}
inline double solve(double x)
{
	return a*x*x + b*x + c;
}
inline double square(double x)
{
	return x*x;
}
int main()
{
	//a = 2;
	//b = 8;
	//c = 2;
	//xp = -2;
	//yp = 6;
	cin >> a >> b >> c >> xp >> yp;
	//if (abs(yp-solve(xp))<0.0001)
	//{
	//	cout << 0.000 << endl;
	//	return 0;
	//}
	cout.precision(3);
	cout.setf(ios::fixed);
	if (a == 0 && b == 0 &&c==0)
	{
		cout << 0.000 << endl;
		return 0;
	}
	getRange();
	double dl=0.0, dr=0.0;
	while ((high - low) > 0.0001)
	{
		double lm = low + (high - low) / 3;
		double rm = high - (high - low) / 3;
		dl = sqrt(square(xp - lm) + square(solve(lm) - yp));
		dr = sqrt(square(xp - rm) + square(solve(rm) - yp));
		if (dl < dr)
			high = rm;
		else
			low = lm;
	}
	dl = sqrt(square(xp - low) + square(solve(low) - yp));
	int temp2 = dl * 1000 + 0.5;
	double answer = temp2 / 1000.0;
	//double answer =(double)((int)(dl* 100 + 0.5)) / 100;
	std::cout << dl << std::endl;
	//printf("%3lf", answer);
	return 0;

}
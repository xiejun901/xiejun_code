#include<fstream>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define PI 3.141592653
int main()
{
	ifstream cin("B-small-attempt2.in");
	/*auto result = asin(0.5)/3.1415926*180;*/
	FILE *fp=0;
	fp = freopen("B-small-attempt2.out", "w", stdout);
	int testCase;
	cin >> testCase;
	for (int t = 1; t <= testCase; t++)
	{
		int v, d;
		cin >> v >> d;
		double v_double = static_cast<double>(v);
		double d_double = static_cast<double>(d);
		double sin2theta = d*9.8 / v / v;
		if (sin2theta > 1.0)
			sin2theta = 1.0;
		double theta = asin(sin2theta)/2*180/PI;
		if (theta < 0)
			theta = 0.0;
		printf("Case #%d: %.7f\n", t,theta);
	}
	fclose(fp);
	return 0;
}
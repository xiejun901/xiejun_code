#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

double caculate(const vector<long long> &vec, int li, int ri)
{
    double pro=1.0;
    double d = static_cast<double>(ri - li+1);
    for (int i = li; i <= ri; i++)
    {
        pro *= static_cast<double>(vec[i]);
    }
    return pow(pro, 1 / d);
}
int main()
{
    ifstream cin("B-large.in");
    /*auto result = asin(0.5)/3.1415926*180;*/
    FILE *fp = 0;
    fp = freopen("B-large.out", "w", stdout);
    long long testcase;
    cin >> testcase;
    for (long long t = 1; t <= testcase; t++)
    {
        long long n, m;
        cin >> n >> m;
        vector<long long> lens(n);
        for (long long i = 0; i < n; ++i)
        {
            cin >> lens[i];
        }
        cout << "Case #" << t << ": " << endl;
        for (long long j = 0; j < m; j++)
        {
            int li, ri;
            cin >> li >> ri;
            auto result = caculate(lens, li, ri);
            //cout << caculate(lens, li, ri) << endl;
            printf("%.9f\n", result);
        }
    }
    return 0;
}
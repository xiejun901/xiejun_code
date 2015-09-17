#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


bool caculate(long long index,long long k)
{
    if (index == 0)
        return false;
    long long temp = static_cast<long long>(pow(2, index - 1));
    if (k == temp )
    {
        return false;
    }
    else if (k < temp)
    {
        return caculate(index - 1, k);
    }
    else if (k > temp)
    {
        return !caculate(index - 1, temp * 2 - k);
    }
}
long long getlog(long long k)
{
    long long i = 1;
    long long index = 0;
    while (i < k)
    {
        i = i << 1;
        index++;
    }

    return index;
}
long long caculateK(long long k)
{
    long long index = getlog(k+1);
    bool ret=caculate(index, k);
    if (ret)
        return 1;
    else
        return 0;
}
int main()
{
    ifstream cin("A-large.in");
    ofstream cout("A-large.out");
    long long testcase;
    cin >> testcase;
    for (long long t = 1; t <= testcase; ++t)
    {
        long long k;
        cin >> k;
        cout << "Case #" << t << ": " << caculateK(k) << endl;
    }
    return 0;
}


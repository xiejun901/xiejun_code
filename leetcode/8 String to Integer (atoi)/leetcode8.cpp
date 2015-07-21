#include<string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		int n = str.size();
		int i = 0;
		long sign = 1;
		while (str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			sign = str[i] == '+' ? 1 : -1;
			i++;
		}
		long long result=0;
		for (;i < n;++i)
		{
			if (str[i]<'0' || str[i]>'9')
				break;
			result = result * 10 + str[i]-'0';
			if (result*sign > INT_MAX)
				return INT_MAX;
			if (result*sign < INT_MIN)
				return INT_MIN;
		}
		return result*sign;
	}
};
int main()
{
	Solution s;
	s.myAtoi("  -0012a42");
}
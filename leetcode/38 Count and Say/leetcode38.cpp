class Solution {
public:
    string countAndSay(int n) {
        if(n==0)
            return string();
        string result("1");
        int i=2;
        while(i<=n)
        {
            result=caculate(result);
            ++i;
        }
        return result;
    }
    string caculate(const string &str)
    {
        string result;
        auto iter1=str.begin();
        auto iter2=str.begin();
        while(iter2!=str.end())
        {
            if(*iter2!=*iter1)
            {
                result.push_back(iter2-iter1+'0');
                result.push_back(*iter1);
                iter1=iter2;
            }
            else
                ++iter2;
        }
        if(iter2!=iter1)
        {
            result.push_back(iter2-iter1+'0');
            result.push_back(*iter1);
        }
        return result; 
    }
};
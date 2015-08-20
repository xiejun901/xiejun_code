class Solution {
public:
    bool isUgly(int num) {
        if(num<=0)
            return false;
        vector<int> dividered{2,3,5};
        for(auto i : dividered)
        {
            while(num%i==0)
                num/=i;
        }
        return num==1;
    }
};
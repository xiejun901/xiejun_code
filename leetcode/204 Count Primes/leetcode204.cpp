class Solution {
public:
    int countPrimes(int n) {
        vector<int> nums(n,0);
        int count=0;
        for(int i=2;i<n;++i)
        {
            if(nums[i]!=-1)
            {
                int k=i;
                while(k<n)
                {
                    nums[k]=-1;
                    k=k+i;
                }
                count++;
            }
        }
        return count;
    }
	
    int countPrimes2(int n) {
        if(n<=2)
            return 0;
        vector<int> nums(n,0);
        int count=1;
        int upper=sqrt(n);
        for(int i=3;i<n;i+=2)
        {
            if(nums[i]!=-1)
            {
                count++;
                if(i>upper)
                    continue;
                for(int k=i*i;k<n;k+=i)
                    nums[k]=-1;
            }
        }
        return count;
    }
};
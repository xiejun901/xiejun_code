class Solution {
public:
    int reverse(int x) {
        queue<int> nums;
        int y=x>0?x:-x;
        while(y>0){
            nums.push(y%10);
            y/=10;
        }
        long long z=0;
        while(!nums.empty()){
            z=z*10+nums.front();
            nums.pop();
        }
        z=x>0?z:-z;
        if(z>(long long)INT_MAX||z<(long long)INT_MIN)
            return 0;
        else
            return z;
    }
};
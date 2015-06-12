class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int y=x;
        int cnt=1;
        while(y>=10){
            cnt*=10;
            y/=10;
        }
        y=x;
        while(cnt>=1){
            if(y/cnt!=y%10)
                return false;
            y=y%cnt;
            y=y/10;
            cnt=cnt/100;
        }
        return true;
    }
};
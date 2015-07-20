class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        int flag=true;
        if(n<0)
        {
            flag=false;
            n=-n;
        }
        double result=myPowPos(x,n);
        if(flag)
            return result;
        else
            return 1.0/result;
        
    }
    double myPowPos(double x,int n){
        double a[32];
        a[0]=x;
        for(int i=1;i<32;++i)
            a[i]=a[i-1]*a[i-1];
        double pro=1.0;
        for(int i=0;i<32;i++)
        {
            if(n&(1<<i))
                pro=pro*a[i];
        }
        return pro;
    }
};
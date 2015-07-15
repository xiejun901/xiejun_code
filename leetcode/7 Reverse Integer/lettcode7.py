class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        minus=False
        if x<0:
            minus=True
        s=str(abs(x))
        x2=int(s[-1:-1*len(s)-1:-1])
        if x2>2**31-1:
            x2=0
        if minus:
            return -1*x2
        else:
            return x2
 
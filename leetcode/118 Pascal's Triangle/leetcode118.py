class Solution:
    # @param {integer} numRows
    # @return {integer[][]}
    def generate(self, numRows):
        if numRows==0:
            return []
        l=[1]
        r=[l]
        if(numRows==1):
            return r
        i=2
        while i<=numRows:
            temp=list(r[-1])
            temp.append(1)
            for k in range(i-2,0,-1):
                temp[k]=temp[k]+temp[k-1]
            r.append(temp)
            i=i+1
        return r

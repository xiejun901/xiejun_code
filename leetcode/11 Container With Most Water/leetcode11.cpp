class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int ans=0;
        while(i<j)
        {
            int temp=(height[i]<height[j]?height[i]:height[j])*(j-i);
            if(temp>ans)
                ans=temp;
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return ans;
    }
};
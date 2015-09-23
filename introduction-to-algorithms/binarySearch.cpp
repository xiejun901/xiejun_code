#include<vector>
#include<iostream>
using namespace std;
int binarySearch(const vector<int> &vec,int key)
{
    int n=vec.size();
    int low=0;
    int high=n-1;
    while(low<high)
    {
        int mid=(low+high)/2;
        if(key<vec[mid])
            high=mid-1;
        else if(key>vec[mid])
            low=mid+1;
        else
            return mid;
    }
    if(vec[low]==key)
        return low;
    return -1;
}
int binarySearch2(const vector<int> &vec, int key)
{
    int low=0;
    int high=vec.size()-1;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(key>vec[mid])
            low=mid+1;
        else
            high=mid;
    }
    if(vec[low]==key)
        return low;
    return -1;
}
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8};
    int key;
    while(cin>>key)
    {
        cout<<binarySearch2(vec,key)<<endl;
    }
    return 0;
}

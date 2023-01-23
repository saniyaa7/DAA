#include<bits/stdc++.h>
using namespace std;
void sumOfSubset(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>ds)
{
    if(ind==arr.size())
    {
        if(target==0)
            ans.push_back(ds);
        return;
    }
    if(arr[ind]<=target)
    {
        ds.push_back(arr[ind]);
        sumOfSubset(ind+1,target-arr[ind],arr,ans,ds);
        ds.pop_back();

    }
    sumOfSubset(ind+1,target,arr,ans,ds);
    
}
int main()
{
    vector<int>v={3,-5,9,12,36,17,23,15};
    int target=25;
    vector<vector<int>>ans;
    vector<int>ds;
    sumOfSubset(0,target,v,ans,ds);
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
}
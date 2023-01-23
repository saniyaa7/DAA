#include<bits/stdc++.h>
using namespace std;
void MaxMin(vector<int>v,int i,int j,int &max,int &max1,int &min,int &min1)
{
    if(i==j)
    {
        max=v[i];
        min=v[j];
        return;
    }
    else if(i==j-1)
    {
        if(v[i]<v[j])
        {
            max=v[j];
            min=v[i];
        }
        else
        {
             max=v[i];
            min=v[j];
        }
        
        
    }
    else
    {
        int mid=i+(j-i)/2;
        MaxMin(v,i,mid,max,max1,min,min1);
         MaxMin(v,mid+1,j,max1,max,min1,min);
         if(max<max1)
             max=max1;
             
         
         if(min>min1)
            min=min1;
         
    }
}
int main()
{
	vector<int>v={3,-56,2,56,6,8883,76,2,78,-6};
	int max=INT_MIN,max1=INT_MIN,min=INT_MAX,min1=INT_MAX;
	MaxMin(v,0,v.size(),max,max1,min,min1);
	cout<<max<<" "<<min;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 struct Job
{
    int id;
    int dead;
    int profit;
};
int comparison(Job a,Job b)
{
  
    return a.profit>b.profit;
}

void JobSeq(Job arr[],int n)
{
sort(arr,arr+n,comparison);
int result[n];
bool slot[n];
for(int i=0;i<n;i++)
    slot[i]=false;
for(int i=0;i<n;i++)
{
    for(int j=min(n,arr[i].dead)-1;j>=0;j--)
    {
        if(slot[j]==false)
        {
            result[j]=i;
            slot[j]=true;
            break;
        }

    }
}
    for(int i=0;i<n;i++)
    {
        if(slot[i])
            cout<<arr[result[i]].id<<" ";
    }


}
int main()
{ Job arr[]={{1,3,1},
                {2,3,5},
                {3,1,10},
                {4,2,15},
                {5,2,20}};
    int n=sizeof(arr)/sizeof(arr[0]);
    JobSeq(arr,n);
    
}
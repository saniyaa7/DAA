#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item
{
    int value;
    int weight;

};
int cmp(Item a,Item b)
{
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}
int fractionalKnapsack(int w,Item arr[],int n)
{
    sort(arr,arr+n,cmp);
    double finalValue=0.0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].weight<=w)
        {
            finalValue+=arr[i].value;
            w-=arr[i].weight;

        }
        else
        {
            finalValue+=arr[i].value*((double)w/(double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main()
{
    int w=20;
    Item arr[]={{25,18},
                {24,15},
                {15,10}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<fractionalKnapsack(w,arr,n);

}
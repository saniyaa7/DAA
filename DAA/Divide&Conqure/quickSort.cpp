#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&a,int low,int high)
{
	int pivote=low,i=low,j=high;
	while(i<j)
	{
		while(a[i]<a[pivote]&&i<=high)
			i++;
		while(a[j]>a[pivote]&&j>=low)
			j--;
		if(i<j)
		swap(a[i],a[j]);
	}
	swap(a[j],a[pivote]);
	return j;
}
void quickSort(vector<int>&v,int low,int high)
{
	if(low<high)
	{
		int p=partition(v,low,high);
		quickSort(v,low,p-1);
		quickSort(v,p+1,high);
	}
}
int main()
{
	vector<int>v={5,2,4,23,65,1,7,78};
	quickSort(v,0,v.size()-1);
	for(auto i:v)
		cout<<i<<" ";
}
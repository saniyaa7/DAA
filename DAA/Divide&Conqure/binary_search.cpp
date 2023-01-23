#include<bits/stdc++.h>
using namespace std;
int binarySearch1(vector<int>a,int l,int h,int x)
{
	if(l<=h)
	{
		int mid=(l+h)/2;
		if(x==a[mid])
			return mid;
		else if(x<a[mid])
			return binarySearch1(a,l,mid-1,x);
		else
			return binarySearch1(a,mid+1,h,x);
	}
	return -1;
}
int binarySearch2(vector<int>a,int l,int h,int x)
{
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(a[mid]==x)
			return mid;
		else if(x<a[mid])
			h=mid-1;
		else
			l=mid+1;
	}
	return -1;
}
int main()
{
	vector<int>v={1,2,3,4,5,6,60,8,9};
	cout<<binarySearch2(v,0,v.size()-1,60);
}
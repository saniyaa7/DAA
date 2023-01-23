#include<bits/stdc++.h>
using namespace std;
int minComputation(int n,int files[])
{
	priority_queue<int,vector<int>,greater<int> >pq;
	for(int i=0;i<n;i++)
	pq.push(files[i]);
	int count=0;
	
	
	while(pq.size()>1)
	{
		int a=pq.top();
		pq.pop();
		int b=pq.top();
		pq.pop();
		int tmp=a+b;
		
		count+=tmp;
		pq.push(tmp);
	}
	return count;
}
int main(){
	
	int files[]={5,10,20,30,30};
	int n=sizeof(files)/sizeof(files[0]);
	cout<<"Minimum Computation: "<<minComputation(n,files);
	return 0;
}
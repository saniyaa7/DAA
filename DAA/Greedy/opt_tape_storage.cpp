///single tape

// #include<bits/stdc++.h>
// using namespace std;
// void findOrderMRT(int l[],int n)
// {
// 	sort(l,l+n);
// 	double MRT=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		int sum=0;
// 		for(int j=0;j<=i;j++)
// 			sum+=l[j];
// 		MRT+=sum;
// 	}
// 	MRT/=n;
// 	cout<<"MRT: "<<MRT;
// }
// int main()
// {
// 	int l[]={5,10,3};
// 	int n=sizeof(l)/sizeof(l[0]);
// 	findOrderMRT(l,n);
// 	return 0;
// }

//multiple tapes

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cout<<"Enter the number of file: ";
	cin>>n;
	vector<int>v[n];
	cout<<"Enter the files:\n";
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<"\nEnter the number of tapes: ";
	cin>>m;
	sort(v.begin(),v.end());
	vector<double>ans(m,0);
	vector<double>len(m,0);
	cout<<"\n";
	for(int i=0;i<v.size();i++)
	{
		ans[i%m]+=v[i];
		cout<<"program file "<<v[i]<<" add to tape "<<i%m<<endl;
		len[i%m]++;

	}
	cout<<"\nMRT of "<<m<<" tapes:\n";
	for(int i=0;i<m;i++)
	{
		ans[i]=ans[i]/len[i];
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	
}

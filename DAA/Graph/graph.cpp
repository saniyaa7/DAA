#include<iostream>
#include<vector>
#include<pair>
using namespace std;
#define M 100
/*int adj[M][M];
int n;
void creat_graph();
void insert(int ,int);
int del(int,int);
void display();
int main()
{
  int ch,org,dest;
  creat_graph();
    while(1)
    {
       cout<<"\n1.insert 2.delete 3.display 4.exit\nEnter your choice: ";
      cin>>ch;
        switch(ch)
        {
            case 1:cout<<"\nEnter the edge to be inserted: ";
            cin>>org>>dest;
            insert(org,dest);
            break;
            case 2:cout<<"\nEnter the edge to be deleted: ";
             cin>>org>>dest;
            x=del(org,dest);
            (x!=-1)?cout<<"\nEdge deleted"<<org<<","<<dest :cout<<"\nThis edge is not exist";
            break;
            case 3:display();
            break;
            case 4:exit(1);
            
        }
    }
}
void creat_graph()
{
    int org,dest;
    cout<<"\nEnter the number of vertices:";
    cin>>n;
    for(int i=1;i<=n*(n-1);i++)
    {
       cout<<"\nEnter the edge "<<i;
        cin>>org>>dest;
        if(org==-1&&dest==-1)
            break;
        if(org<0||dest<0||org>n||dest>n)
        {
            cout<<"invalid edge!!";
            i--;
        }
        else
            adj[org][dest]=1;

    }
}
void insert(int org,int dest)
{
    if(org>n||org<0)
       cout<<"\nInvalid origin!!";
    else if(dest>n||dest<0)
       cout<<"\nInvalid destination!!";
    else if(adj[org][dest]==1)
       cout<<"\nEdge already exits";
    else
        adj[org][dest]=1;
}
int del(int org,int dest)
{
     if(org<0||dest<0||org>n||dest>n)
         return -1;

     if(adj[org][dest]!=1)
        return -1;
     adj[org][dest]=0;
     return 1;

}
void display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }
}
*/


//Adjecency Matrix

/*int main()
{
   int n,u,v;
   cin>>n;
     int adj[n][n]={0};
   for(int i=0;i<n*(n-1)/2;i++)
   {
    cout<<"Enter the Edge "<<i<<" (-1 -1 for break): ";
    cin>>u>>v;
    if(u==-1&&v==-1)
        break;
    if(u<0||u>n||v<0||v>n)
        {
            cout<<"Enter valid Edge!!";
            i--;
        }
        adj[u][v]=1;
        adj[v][u]=1;


   }
   cout<<"\nAdjecency Matrix:\n";
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
        cout<<adj[i][j]<<" ";
    cout<<endl;
   }

}
*/


//Adjecency list
// int main()
// {
//     int n,u,v;
//    cin>>n;
//      vector<int>adj[n];
//    for(int i=0;i<n*(n-1)/2;i++)
//    {
//     cout<<"Enter the Edge "<<i<<" (-1 -1 for break): ";
//     cin>>u>>v;
//     if(u==-1&&v==-1)
//         break;
//     if(u<0||u>n||v<0||v>n)
//         {
//             cout<<"Enter valid Edge!!";
//             i--;
//         }
//        adj[u].push_back(v);
//        adj[v].push_back(u);


//    }
//    cout<<"\nAdjecency List:\n";
//    for (int v = 0; v < n; ++v) {
//         cout << "\n Adjacency list of vertex " << v
//              << "\n head ";
//         for (auto x : adj[v])
//             cout << "-> " << x;
//        cout<<endl;
//     }
// }


#include<bits/stdc++.h>
using namespace std;
struct Graph
{
int V;
list<pair<int, int> >* adj;
Graph(int V);
void addEdge(int u,int v,int w);
void display();
};
Graph::Graph(int V)
{
	this->V=V;
	adj = new list<pair<int,int>>[V];
}
void Graph::addEdge(int u,int v,int w)
{
	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}
void Graph::display()
{
	for(int i=0;i<V;i++)
	{
		list<pair<int,int>> ::iterator it;
		for(it=adj[i].begin();it!=adj[i].end();++it)
		{
			cout<<i<<" -->";
			cout<<(*it).first<<" "<<(*it).second<<endl;
		}
	}
}
int main()
{
Graph g(3);
g.addEdge(0,1,20);
g.addEdge(0,2,10);
g.addEdge(1,2,15);
g.display();
}
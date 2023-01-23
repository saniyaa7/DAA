#include<bits/stdc++.h>
using namespace std;
class Graph
{
    public:
   map<int,int>vis;
    map<int,list<int>>adj;
    void addEdge();
    void DFS(int);

};
void Graph::addEdge()
{
     int n,u,v;
   cin>>n;
     
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
       adj[u].push_back(v);
     


   }
}
void Graph::DFS(int s)
{
    cout<<s<<" ";
    for(auto i:adj[s])
    {
        if(vis[i]!=1)
        {
            vis[i]=1;
            DFS(i);
        }
    }
}
int main()
{
     Graph g;
    g.addEdge();
         g.vis[0]=1;
        g.DFS(0);

}
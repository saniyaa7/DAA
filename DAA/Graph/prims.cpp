#include<bits/stdc++.h>
using namespace std;
class graph
{
public:
    list<pair<int,int> >* adj;
    int V;
    graph(int V)
    {
        this->V=V;
        adj=new list<pair<int,int> >[V];

    }
    void addEdge(int u,int v,int w);
    void prims();
};
void graph::addEdge(int u,int v,int w)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});

}
void graph::prims()
{
   vector<int>key(V,INT_MAX);
   vector<int>parent(V,-1);
   vector<int>vis(V,0);
   priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
   pq.push({0,0});
   int sum=0;
   while(!pq.empty())
   {
       int u=pq.top().second;
       int w=pq.top().first;
       pq.pop();
       if(vis[u]) continue;
       vis[u]=1;
       sum+=w;
       list<pair<int,int> >::iterator it;
       for(it=adj[u].begin();it!=adj[u].end();it++)
       {
           int v=(*it).first;
           int wt=(*it).second;
           if(!vis[v]&&key[v]>wt)
           {
               key[v]=wt;
               pq.push({wt,v});
               parent[v]=u;
           }
       }
   }
   cout<<sum<<endl;
   for(int i=1;i<V;i++)
    cout<<parent[i]<<" - "<<i<<" --> "<<key[i]<<endl;
}
int main()
{
    graph g(5);
g.addEdge(0,1,2);
g.addEdge(0,3,6);
g.addEdge(1,2,3);
g.addEdge(1,3,8);
g.addEdge(1,4,5);
g.addEdge(2,4,7);
g.prims();
}

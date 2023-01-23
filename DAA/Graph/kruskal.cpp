#include<bits/stdc++.h>
using namespace std;
class graph
{
public:
    vector<vector<int> >edge;
    
    int V;
    graph(int V)
    {
        this->V=V;
        

    }
    void addEdge(int u,int v,int w);
    void kruskal();
    void makeset(vector<int>&p,vector<int>&r);
    int findParent(vector<int>&p,int node);
    void unionSet(int u,int v,vector<int>&p,vector<int>&r);
};
void graph::addEdge(int u,int v,int w)
{
    edge.push_back({w,u,v});


}
int graph::findParent(vector<int>&p,int node)
{
    if(p[node]==node)
    return node;
    p[node]=findParent(p,p[node]);
}
void graph::makeset(vector<int> &p,vector<int> &r)
{
    for(int i=0;i<V;i++)
    {
  p[i]=i;
    r[i]=0;
    }
  
}
void graph::unionSet(int u,int v,vector<int> &p,vector<int> &rank)
{
    u=findParent(p,u);
     v=findParent(p,v);
     if(rank[u]<rank[v])
        p[u]=v;
    else if(rank[v]<rank[u])
        p[v]=u;
    else
    {
        p[v]=u;
        rank[u]++;
    }
}
void graph::kruskal()
{
  sort(edge.begin(),edge.end());
  int ans=0;
  vector<int>parent(V);
  vector<int>rank(V);
  makeset(parent,rank);
  for(int i=0;i<edge.size();i++)
  {
    int u=findParent(parent,edge[i][1]);
    int v=findParent(parent,edge[i][2]);
    int wt=edge[i][0];
    if(u!=v)
    {
        ans+=wt;
        unionSet(u,v,parent,rank);

    }

  }
  cout<< ans;
}
int main()
{
    graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);
    g.addEdge(2,0,6);
    g.addEdge(0,3,5);
    g.kruskal();


}
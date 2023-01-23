#include<bits/stdc++.h>
using namespace std;

class Graph{
   

    public:
    map<int,int>vis;
    vector<int>adj[10];
    void addEdge(int u,int v);
     void BFS();


};
void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}
void Graph::BFS()
{
    vis[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        for(auto i:adj[node])
        {
            if(!vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                }
        }
    }

}
int main()
{
    Graph g;
    g.addEdge(0,1);
     g.addEdge(0,9);
      g.addEdge(1,2);
       g.addEdge(2,0);
        g.addEdge(2,3);
         g.addEdge(9,3);
        g.BFS();
         

}
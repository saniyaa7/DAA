#include<bits/stdc++.h>
using namespace std;
struct Graph
{
int V;
list<pair<int, int> >* adj;
Graph(int V);
void addEdge(int u,int v,int w);
void dijkstra(int source);
};
Graph::Graph(int V)
{
	this->V=V;
	adj = new list<pair<int,int> >[V];
}
void Graph::addEdge(int u,int v,int w)
{
	adj[u].push_back({v,w});
	adj[v].push_back({u,w});
}
void Graph::dijkstra(int source)
{
	vector<int>dist(V);
	for(int i=0;i<V;i++)
		dist[i]=INT_MAX;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,source});
	dist[source]=0;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		list<pair<int,int> >::iterator x;
		for(x=adj[u].begin();x!=adj[u].end();x++)
		{
			int v=(*x).first;
			int w=(*x).second;

			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	for(int i=0;i<V;i++)
		cout<<i<<" "<<dist[i]<<endl;

}
int main()
{
int V = 9;
	Graph g(V);


	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14);
	g.addEdge(4, 5, 10);
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);


	g.dijkstra(0);
	return 0;
}

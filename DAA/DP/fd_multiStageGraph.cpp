#include<bits/stdc++.h>
#define INF INT_MAX
#define N 13
#define k 6
using namespace std;
void shortestDist(int graph[N][N])
{
    int cost[N];
    cost[N-1]=0;
    int dist[N];
    for(int i=N-2;i>=0;i--)
    {
        cost[i]=INF;
        for(int j=i;j<N;j++)
        {
            if(graph[i][j]==INF)
                continue;
            if(cost[i]>graph[i][j]+cost[j])
            {
                cost[i]=graph[i][j]+cost[j];
                dist[i]=j;
            }
        }
    }
    int p[k];
    p[1]=1,p[k-1]=N-1;
    for(int j=2;j<k-1;j++)
        p[j]=dist[p[j-1]];
    cout<<cost[1]<<endl;
    cout<<endl;
    for(int i=1;i<k;i++)
        cout<<p[i]<<" ";
}
int main()
{

    int graph[N][N]={{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
                {INF,INF,9,7,3,2,INF,INF,INF,INF,INF,INF,INF},
                {INF,INF,INF,INF,INF,INF,4,2,1,INF,INF,INF,INF},
                {INF,INF,INF,INF,INF,INF,2,7,INF,INF,INF,INF,INF},
                {INF,INF,INF,INF,INF,INF,INF,INF,11,INF,INF,INF,INF},
                {INF,INF,INF,INF,INF,INF,INF,11,8,INF,INF,INF,INF},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,6,5,INF,INF},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,4,3,INF,INF},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,5,6,INF},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,4},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,2},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,5},
                {INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF}
                };
            shortestDist(graph);
}

#include<bits/stdc++.h>
using namespace std;
#define N 13
#define k 5
#define INF INT_MAX
void shortestDist(int graph[N][N])
{
    int cost[N],p[k+1],d[N];
    cost[1]=0;
   int j=0,sum=0,r=0;
   for(j=2;j<N;j++)
   {
    for(r=1;r<N;r++)
    {
        if(graph[r][j]!=INF && graph[r][j]+cost[r]<cost[j])
        {
            cost[j]=graph[r][j]+cost[r];
            d[j]=r;
        }
    }
   }
   p[1]=1;
   p[k]=N-1;
   for(j=k-1;j>=2;j--)
        p[j]=d[p[j+1]];
    cout<<cost[N-1];
    cout<<"\n";
    for(int i=1;i<=k;i++)
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
#include<bits/stdc++.h>
using namespace std;
#define N 3
#define INF INT_MAX
void floydWarshall(int mat[N][N])
{
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(mat[i][j]>mat[i][k]+mat[k][j])
                    mat[i][j]=mat[i][k]+mat[k][j];
            }
        }
    }
}
void display(int mat[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int mat[N][N]={{0,4,11},
                    {6,0,2},
                    {3,INF,0}};
    floydWarshall(mat);
    display(mat);
}
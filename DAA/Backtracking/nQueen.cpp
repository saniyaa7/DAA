 #include<bits/stdc++.h>
 using namespace std;
 #define N 4
 void printSolution(int board[N][N])
 {
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j])
                cout<<'Q'<<" ";
            else
                cout<<"-"<<" ";
        }
        cout<<endl;
    }
    cout<<"\n_____________________________________\n"<<endl;
    
 }
 bool isSafe(int board[N][N],int row,int col)
 {
    
    for(int i=row;i>=0;i--)
    {
        if(board[i][col]==1)
            return false;
    }
    
    for(int i=row,j=col;i>=0&&j>=0;i--,j--)
    {
         if(board[i][j]==1)
            return false;
    }
     for(int i=row,j=col;i>=0&&j<N;i--,j++)
    {
         if(board[i][j]==1)
            return false;
    }
    return true;
 }
 bool nQueen(int board[N][N],int row)
 {
    if(row==N)
    {
        printSolution(board);
        return true;
    }
        
    
    for(int col=0;col<N;col++)
    {
        if(isSafe(board,row,col))
        {
        board[row][col]=1;
        printSolution(board);
        if(nQueen(board,row+1))
        
            return true;
        board[row][col]=0;
        
        }
        

    }
    return false;
 }
 int main()
 {
    int board[N][N]={{0,0,0,0},
               {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0}};
    if(!nQueen(board,0))
        cout<<"Solution is not possible!";

 }




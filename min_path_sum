//Time Complexity: O(N*M)
//Space Complexity: O((M-1)+(N-1)) + O(N*M)


//MINIMUM PATH SUM in GRID

#include<bits/stdc++.h>
using namespace std;

int dfs(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& grid)
{
    if(i==0&&j==0)
    {
        return grid[0][0];
    }
    else if(i<0||j<0)
    {
        return 1e9;
    }
    else if(dp[i][j]!=-1)
        return dp[i][j];
    
    int up=   grid[i][j]+ dfs(i-1,j,dp,grid);
    int left= grid[i][j]+dfs(i,j-1,dp,grid);
    return dp[i][j]=min(left,up);
}

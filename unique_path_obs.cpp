#include <bits/stdc++.h>

using namespace std;

int CountWaysObstacles(int i, int j, vector<vector<int> > &grid, vector<vector<int> > 
&dp) {
  if(i>0 && j>0 && grid[i][j]==-1)
  {
     return 0; 
  }
  if(i==0 && j == 0)
  {
    return 1;
  }
  if(i<0 || j<0)
  {
    return 0;
  }
  if(dp[i][j]!=-1) 
  {
    return dp[i][j];
  }
    
  int up = CountWaysObstacles(i-1,j,grid,dp);
  int left = CountWaysObstacles(i,j-1,grid,dp);
  
  return dp[i][j] = up+left;
  
}


int main() {

  vector<vector<int> > grid{{0,0,0},
                            {0,-1,0},
                            {0,0,0}};
                            
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int> > dp(n+1,vector<int>(m+1,-1));
  cout<<CountWaysObstacles(n-1,m-1,grid,dp);
}
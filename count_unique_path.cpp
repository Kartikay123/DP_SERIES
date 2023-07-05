#include <bits/stdc++.h>

using namespace std;

int countWays(int i, int j, vector<vector<int> > &dp) {
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
    
  int up = countWays(i-1,j,dp);
  int left = countWays(i,j-1,dp);
  
  return dp[i][j] = up+left;
  
}


int main() 
{

  int m=3;
  int n=7;
  vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
  cout<<countWays(m-1,n-1,dp);
}
// Time Complexity: O(N*N)
// Space Complexity: O(N) + O(N*N)

#include <bits/stdc++.h>
using namespace std;

int minimumPathSum(int i, int j, vector<vector<int>>&triangle,int n,vector<vector<int> > &dp) 
{
  
  if(dp[i][j]!=-1)
  return dp[i][j];
  
  if(i==n-1) return triangle[i][j];
    
  int down = triangle[i][j]+minimumPathSum(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+minimumPathSum(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
  
}



int main() {

  vector<vector<int> > triangle{{1},
                                {2,1},
                                {3,9,7},
                                {5,7,6,10}};
                            
  int n = triangle.size();
  vector<vector<int> > dp(n+1,vector<int>(n+1,-1));
  cout<<minimumPathSum(0,0,triangle,n,dp);
}
//TC o(N*N)
//SC o(N*N)+o(N)
#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(int arr[],int n,int ind,int prev_index,vector<vector<int>> &dp) 
{
       if(ind == n)
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + lengthOfLIS(arr,n,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + lengthOfLIS(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take); 
}

int main() {
	
	int arr[] = {0,1,0,3,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    cout<< lengthOfLIS(arr,n,0,-1,dp)<<endl;
	
	return 0;
}
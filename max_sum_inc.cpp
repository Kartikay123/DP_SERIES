//TC o(N*N)
//SC o(N*N)+o(N)
#include<bits/stdc++.h>
using namespace std;

int solve(int ind ,int prev , int arr[] ,int n,vector<vector<int>>&dp){
        if(ind==n)
        return 0;
        
        if(dp[ind][prev+1]!=-1)
        return dp[ind][prev+1];
        
        int nottake=0+solve(ind+1,prev,arr,n,dp);
        
        int take=0;
        if(prev==-1||arr[ind]>arr[prev])
         take =arr[ind]+solve(ind+1,ind,arr,n,dp);
         
        return dp[ind][prev+1]=max(take,nottake);
    }

int main()
{
    int arr[] = {0,1,0,3,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	cout<<solve(0,-1,arr,n,dp)<<endl;
    return 0;
}	  
	   
	    

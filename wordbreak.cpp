 // // TC o(expo)
// // SC o(N)

#include <bits/stdc++.h>

using namespace std;
 
 bool solve(int i,string &s,unordered_map<string,int>&mp,vector<int>&dp)
    {
       if(i>=s.size())return true;
        
        if(dp[i]!=-1)return dp[i];
        
        bool ans=0;
        string temp="";
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(mp.find(temp)!=mp.end())
            {
                ans = ans || solve(j+1,s,mp,dp);
            }
            
        }
        return dp[i] = ans;
    }
    
 

   
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_map<string,int>mp;
        
        for(auto it:wordDict)mp[it]++;
        
        return solve(0,s,mp,dp);
    }

    int main()
    {
        string s="applepenapple";
        vector<string>wordDict = {"apple","pen"};
        cout<<wordBreak(s,wordDict);
        return 0;
    }
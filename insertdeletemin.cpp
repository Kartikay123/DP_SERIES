//TC o(N*N)
//SC o(N*N)+O(N)
#include <bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);

    else
        return dp[i][j] = 0 + max(lcs(s1, s2, i, j - 1, dp), lcs(s1, s2, i - 1, j, dp));
}

int main()
{

    string s1 = "abcd";
    string s2= "anc";
    //MINIMUM OPERATION TO CONVERT s1 to s2
    int n = s1.size();
    int m= s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout << n+m-(2*lcs(s1,s2, n - 1, m - 1, dp));
}
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

    string s = "bbabcbcab";
    int n = s.size();
    string t = s;
    reverse(s.begin(), s.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout << lcs(s, t, n - 1, n - 1, dp);
}
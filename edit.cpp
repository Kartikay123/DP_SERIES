// TC o(N*M)
// SC o(N*M)+o(N+M)
#include <bits/stdc++.h>
using namespace std;

int editDis(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j])
    {
        return dp[i][j] = 0 + editDis(S1, S2, i - 1, j - 1, dp);
    }

    return dp[i][j] = 1 + min(editDis(S1, S2, i - 1, j - 1, dp),
                              min(editDis(S1, S2, i - 1, j, dp), editDis(S1, S2, i, j - 1, dp)));
}

int main()
{

    string s1 = "horse";
    string s2 = "ros";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << editDis(s1, s2, n - 1, m - 1, dp) << endl;
}
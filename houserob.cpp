//TC =O(N)
//SC O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &val, vector<int> &dp)
{
    if(i<0)
    return 0;
    if (i == 0)
    {
        return val[0];
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int rob= val[i]+solve(i-2,val,dp);
    int nrob= solve(i-1,val,dp);

    return dp[i] = max(rob, nrob);
}

int main()
{

    vector<int> val{30, 10, 60, 130, 50};
    int n = val.size();
    vector<int> dp(n + 1, -1);
    cout << solve(n - 1, val, dp);
}
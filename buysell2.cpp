//SC O(N*2)+O(N)
//TC O(N*2)
#include<bits/stdc++.h>
using namespace std;
int solve(int i, int buy, vector<vector<int>> &dp, vector<int> &prices, int n)
{
    if (i == n)
        return 0;
    if (dp[i][buy] != -1)
    {
        return dp[i][buy];
    }
    if (buy)
    {

        return dp[i][buy] = max(-prices[i] + solve(i + 1, 0, dp, prices, n), solve(i + 1, 1, dp, prices, n));
    }

    int a1 = prices[i] + solve(i + 1, 1, dp, prices, n);
    int a2 = 0 + solve(i + 1, 0, dp, prices, n);
    return dp[i][buy] = max(a1, a2);
}

int main()
{
    vector<int>prices={7, 1, 5, 3, 6, 4};
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1));
    cout << solve(0, 1, dp, prices, n);
    return 0;
}
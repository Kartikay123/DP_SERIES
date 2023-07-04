// TC o(N*N)
// SC o(N*N)+o(N)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int amount, int n, vector<vector<int>> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (n < 0 || amount < 0)
    {
        return INT_MAX - 1;
    }
    if (dp[n][amount] != -1)
    {
        return dp[n][amount];
    }

    int one = solve(coins, amount, n - 1, dp);
    int two = 1 + solve(coins, amount - coins[n], n, dp);
    return dp[n][amount] = min(one, two);
}

int coinChange(vector<int> &coins, int amount)
{
    vector<vector<int>> h(coins.size() + 1, vector<int>(amount + 1, -1));
    int ans = solve(coins, amount, coins.size() - 1, h);
    return (ans < INT_MAX - 1) ? ans : -1;
}
int main()
{

    vector<int> arr = {3};
    int target = 4;

    int n = arr.size();

    cout << "The total number of ways is " << coinChange(arr,target);
}
// TC O(N*K)
//SC O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &height, int k, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
            int jump = solve(i - j, height, k, dp) + abs(height[i] - height[i - j]);
            mini = min(jump, mini);
        }
    }
    return dp[i] = mini;
}

int main()
{

    vector<int> height{20, 10, 60, 50};
    int n = height.size();
    int k = 2;
    vector<int> dp(n + 1, -1);
    cout << solve(n - 1, height, k, dp);
}

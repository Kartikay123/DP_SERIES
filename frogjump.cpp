//TC =O(N)
//SC O(N)
#include <bits/stdc++.h>
using namespace std;

int solve(int i, vector<int> &height, vector<int> &dp)
{
    if (i == 0)
    {
        return 0;
    }
    if (dp[i] != -1)
    {
        return dp[i];
    }
    int two = INT_MAX;
    if (i > 1)
        two = solve(i - 2, height, dp) + abs(height[i] - height[i - 2]);

    int one = solve(i - 1, height, dp) + abs(height[i] - height[i - 1]);

    return dp[i] = min(one, two);
}

int main()
{

    vector<int> height{30, 10, 60, 30, 50};
    int n = height.size();
    vector<int> dp(n + 1, -1);
    cout << solve(n - 1, height, dp);
}
// TC o(N*K)
// // SC o(N*K)+o(N)

#include <bits/stdc++.h>
using namespace std;

int CountWays(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return 1;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int notTaken = CountWays(ind - 1, target, arr, dp);

    int taken = 0;
    if (arr[ind] <= target)
        taken = CountWays(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken + taken;
}

int main()
{

    vector<int> arr = {1, 2, 2, 3};
    int k = 3;
    int n=arr.size();
    vector<vector<int>> dp(arr.size() + 1, vector<int>(k + 1, -1));
    cout << "The number of subsets found are " << CountWays(n-1,k,arr,dp);
     return 0;
}
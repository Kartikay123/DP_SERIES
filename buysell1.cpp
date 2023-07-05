// TC O(N)
// SC O(1)

#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &arr)
{
    int maxProfit = 0;
    int mini = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int curr = arr[i] - mini;
        maxProfit = max(maxProfit, curr);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout<<maximumProfit(arr);
}
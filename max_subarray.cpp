//TC o(N)
//SC o(1)
#include<bits/stdc++.h>
using namespace std;
 int maxProduct(vector<int>&nums)
    {
        int ans = nums[0];
        int max_prod = nums[0];
        int min_prod = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(max_prod, min_prod);
            }
            max_prod = max(nums[i], max_prod * nums[i]);
            min_prod = min(nums[i], min_prod * nums[i]);
            ans = max(ans, max_prod);
        }
        return ans;
    }

int main() 
{
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProduct(nums);
    return 0;
}
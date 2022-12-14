/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400*/

class Solution {
private:
    int n;
    vector<int> cache;
    const int INF = 987654321;
    int rob(vector<int>& nums, int index) {
        if (index == n) return 0;
        if (index > n) return -INF;
        
        int &ret = cache[index];
        if (ret != -1) return ret;
        
        int result = nums[index];
        result = max(result, nums[index] + rob(nums, index + 2));
        result = max(result, nums[index] + rob(nums, index + 3));
        return ret = result;
    }
    
public:
    int rob(vector<int>& nums) {
        n = nums.size();
        cache = vector<int>(n, -1);
        return max(rob(nums, 0), rob(nums, 1));
    }
};

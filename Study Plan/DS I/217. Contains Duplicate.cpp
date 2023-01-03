/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 
Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sort the nums...
        sort(nums.begin(), nums.end());
        // Traverse all the elements through the loop...
        for(int idx = 0; idx < nums.size() - 1; idx++) {
            // Check the duplicate element...
            if(nums[idx] == nums[idx + 1])
                return true;
        }
        // Otherwise return false...
        return false;
    }
};

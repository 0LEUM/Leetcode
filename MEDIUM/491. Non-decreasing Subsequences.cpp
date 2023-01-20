/*Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

 
Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
 

Constraints:

1 <= nums.length <= 15
-100 <= nums[i] <= 100*/

class Solution {
public:
    void func(int idx,vector<int>&nums,vector<int>&a,set<vector<int>>&ans){
        int n=nums.size();
        //If we have our index greater than or equal to sizeof nums then we cant go further 
        //so we will check if there is a subarray with size greater than equal to 2
        if(idx>=n){
            if(a.size()>=2){
                //if we have such subarray we will insert it to the set
                ans.insert(a);
            }
            return ;
        }
        //now for [0,n-1] index we will check either condition for inserting into a vector
            //1. if a vector is empty so we can push the element easily
            //2. if a last element is less than equal to cur element
        if(!a.size()||nums[idx]>=a.back()){
            //we will push back into a vector and then call the func for idx+1;
            a.push_back(nums[idx]);
            func(idx+1,nums,a,ans);
            //we are removing element because a vector is being passed by reference
            a.pop_back();
        }
        //calling the function without that value
        func(idx+1,nums,a,ans); 
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        //we have made a temp vector for storing the values till an index
        vector<int>temp;
        //we have made a set of vector because there can be repeated elements which cause 
        //repetion of subarray so set doesnt allow repetion of values
        set<vector<int>>ans;
        //we are calling our recursive function giving starting index to 0
        func(0,nums,temp,ans);
        //typecasting the set into vector and returning it we can do it manually also
        return vector(ans.begin(),ans.end());
        
    }
};

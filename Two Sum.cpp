class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int num=target-nums[i];
            if(m.find(num)!=m.end())
            {
                ans.emplace_back(m[num]);
                ans.emplace_back(i);
                return ans;
            }
            m[nums[i]]=i;
        }
        return {};
    }
};

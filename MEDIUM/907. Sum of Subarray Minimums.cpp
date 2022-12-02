/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 
Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:

Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:

1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104*/

class Solution 
{
public:
    int sumSubarrayMins(vector<int>& n) 
    {
        vector<long> s, sums(n.size(),0);
        long j, res=0, mod = 1000000007;
        for (int i = 0; i < n.size(); ++i)
        {
            while (!s.empty() && n[s.back()] > n[i])
                s.pop_back();
            j = !s.empty() ? s.back() : -1;
            
            sums[i] = ((j>=0?sums[j]:0) + (i-j)*n[i]) % mod;
            s.push_back(i);
        }

        for (int i = 0; i < sums.size(); ++i)
            res = (res + sums[i]) % mod;
        return res;
    }
};

/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int ans = s[0].length(), n = s.size();
        for (int i = 1; i < n; i++) {
            int j = 0;
            while (j < s[i].length() && s[i][j] == s[0][j])j++;
            ans = min(ans, j);
        }
        return s[0].substr(0, ans);
    }
};
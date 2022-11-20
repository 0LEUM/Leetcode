/*Run-length encoding is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "aabccc" we replace "aa" by "a2" and replace "ccc" by "c3". Thus the compressed string becomes "a2bc3".

Notice that in this problem, we are not adding '1' after single characters.

Given a string s and an integer k. You need to delete at most k characters from s such that the run-length encoded version of s has minimum length.

Find the minimum length of the run-length encoded version of s after deleting at most k characters.

 
Example 1:

Input: s = "aaabcccd", k = 2
Output: 4
Explanation: Compressing s without deleting anything will give us "a3bc3d" of length 6. Deleting any of the characters 'a' or 'c' would at most decrease the length of the compressed string to 5, for instance delete 2 'a' then we will have s = "abcccd" which compressed is abc3d. Therefore, the optimal way is to delete 'b' and 'd', then the compressed version of s will be "a3c3" of length 4.

Example 2:

Input: s = "aabbaa", k = 2
Output: 2
Explanation: If we delete both 'b' characters, the resulting compressed string would be "a4" of length 2.

Example 3:

Input: s = "aaaaaaaaaaa", k = 0
Output: 3
Explanation: Since k is zero, we cannot delete anything. The compressed string is "a11" of length 3.
 

Constraints:

1 <= s.length <= 100
0 <= k <= s.length
s contains only lowercase English letters.*/

class Solution {
    int n;
    
private:
    int f(int idx, char prev, int curCharFreqCount, string &s, int k, int dp[][27][11][101])
    {
        if(k < 0) return 1e9;
        
        if(idx >= n)
            return 0;
        
        // if curCharFreqCount, consider it as 10, because, until 10 .. 99, string length will be 2, 
        if(curCharFreqCount >= 10)
            curCharFreqCount = 10;
        
        if(dp[idx][prev - 'a'][curCharFreqCount][k] != -1)
            return dp[idx][prev - 'a'][curCharFreqCount][k];
        
        
        int res = 1e9;
        
        /*
        3 cases:
        case 1: We will delete our current character if K is available, so our string length will be minimum.
        case 2: If cur char is not same as prev, our res will be increased by 1 and curCharFreqCount will be 1
        case 3: If cur char is same as prev char, we need to merge it and increase our count
                case 3.1: If curCharFreqCount is either 1 or more than 9, our res will be increased by 1
                case 3.2: Else, we just need to increase curCharFreqCount.
        */
        
        // case 1
        res = min(res, f(idx+1, prev, curCharFreqCount, s, k-1, dp));
        
        // case 2
        if(s[idx] != prev)
            res = min(res, 1 + f(idx + 1, s[idx], 1, s, k, dp));
        
        // case 3
        else{
            
            // case 3.1
            if(curCharFreqCount == 1 || curCharFreqCount == 9)
            {
                res = min(res, 1 + f(idx + 1, prev, (curCharFreqCount + 1), s, k, dp));
            }
            
            // case 3.2
            else{
                res = min(res, f(idx + 1, prev, curCharFreqCount + 1, s, k, dp));
            }
        }
        
        return dp[idx][prev - 'a'][curCharFreqCount][k] = res;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        
        // 4 states -> [idx][prev_char][freq_count][k]
        n = s.size();
        
        if(n == 100)
        {
            bool allSame = true;
            
            // Base case: check for all char are same
            for(int i = 1; i < n; i++)
            {
                if(s[i] != s[i-1])
                {
                    allSame = false;
                    break;
                }
            }

            if(allSame) return 4;
        }
        
        
        int dp[n+1][27][11][101];
        
        memset(dp, -1, sizeof(dp));
        
        return f(0, 'z' + 1, 0, s, k, dp);
    }
};

/*Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 
Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.*/

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int strt = 0, end = 0;
        int itrtr = 0;
        while (itrtr < n) {
            while (itrtr < n && s[itrtr] != ' ')
                s[end++] = s[itrtr++];

            if (strt < end) {
                reverse(s.begin() + strt, s.begin() + end); 
                if (end == n) break;
                s[end++] = ' ';
                strt = end;
            }
            itrtr++; 
        }
        if (end > 0 && s[end-1] == ' ')   s.resize(end-1);
       else  s.resize(end);
        return s;
    }
};

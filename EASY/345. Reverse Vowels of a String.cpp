/*Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 
Example 1:

Input: s = "hello"
Output: "holle"

Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.*/

class Solution 
{
public:
    string reverseVowels(string s) 
    {
        set<char> vwls = {'a','e','i','o','u','A','E','I','O','U'};
        int l = 0, r = s.size()-1;
        while (l < r)
        {
            l += !vwls.count(s[l]);
            r -= !vwls.count(s[r]);
            if (vwls.count(s[l]) && vwls.count(s[r]))
                swap(s[l++], s[r--]);
        }
        return s;
    }
};

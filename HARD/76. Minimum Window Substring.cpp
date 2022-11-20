/*Given two strings s and t of lengths m and n respectively, return the minimum window 
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 
Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.*/

class Solution {
public:

    string minWindow(string str, string pat) {
           
    int len1 = str.length();
    int len2 = pat.length();
        
     const int no_of_chars = 256;

    if (len1 < len2) {
        return "";
    }

    int hash_pat[no_of_chars] = { 0 };
    int hash_str[no_of_chars] = { 0 };

    
    for (int i = 0; i < len2; i++)
        hash_pat[pat[i]]++;

    int start = 0, start_index = -1, min_len = INT_MAX;

   
    int count = 0; 
    for (int j = 0; j < len1; j++) {
      
        
        hash_str[str[j]]++;

        
        if (hash_str[str[j]] <= hash_pat[str[j]])
            count++;

        if (count == len2) {
          
            while (hash_str[str[start]]
                       > hash_pat[str[start]]
                   || hash_pat[str[start]] == 0) {

                if (hash_str[str[start]]
                    > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }

            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }


    if (start_index == -1) {
     
        return "";
    }

    
    return str.substr(start_index, min_len);
    }
};

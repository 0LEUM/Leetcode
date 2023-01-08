/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 
Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq_s[26]={0}, freq_t[26]={0};
        for(char ch:s) freq_s[ch-'a']++;
        for(char ch:t) freq_t[ch-'a']++;

        for(int i=0;i<26;i++)
            if(freq_s[i] != freq_t[i])  return false;

            return true;
        
    }
};

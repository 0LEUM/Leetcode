/*Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 
Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true
 

Constraints:

1 <= ransomNote.length, magazine.length <= 105
ransomNote and magazine consist of lowercase English letters.*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size()<ransomNote.size()) return false;
        map<char,int>mp;
         for(int i=0; i<magazine.length(); i++) {
            mp[magazine[i]]++;
        }
        
        for(int i=0; i<ransomNote.length(); i++) {
            if(mp[ransomNote[i]]>0) mp[ransomNote[i]]--;
            else return false;
        }
        
        return true;
        
    }
};

/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
       vector<vector<string>>ans;
        
       unordered_map<string, vector<string>>mp;
        
         /*
                Consider example 1 : strs = ["eat","tea","tan","ate","nat","bat"]
                
                After the below opeartion of for loop map will contain
                
                aet -- eat, tea, ate
                ant -- tan, nat
                abt -- bat
        */
        
        for(int i = 0 ; i < strs.size() ; i++)
        {
            string s = strs[i];
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(s);
        }
        
        //now simply put the elements  of second column of map in ans
        
        for(auto i : mp)
        {
            ans.push_back(i.second);
        }

        return ans;
        
    }
};

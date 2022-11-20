/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
 

Constraints:

1 <= s.length <= 104
s consists of only English letters and spaces ' '.
There will be at least one word in s.*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==1){
            if(s[0]==' ') return 0;
            else return 1;
        }
        int i=s.size()-1;
        int j=i;
        while(i>0){
            if(s[i]==' ') 
            while(s[i]==' ' && i>0) i--;
            if(i==0) return !(s[i]==' ');
            j=i;
            while(s[i]!=' ' && i>0) i--;
            if(i!=0 || s[i]==' ') i++;
            break;
        }
        return j-i+1;
    }
};

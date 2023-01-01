/*Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 
Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false
 

Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.*/

class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {
            vector<string> v;

            // separate the string with the whitespaces 
            stringstream ss(s);
            string word;
            while( ss >> word ) v.push_back( word );

            // if data is insufficient 
            if (v.size() != pattern.size()) return false;

            unordered_map<char, string> m;
            set<string> st;

            for (int i = 0; i < pattern.size(); i++){

                if (m.find(pattern[i]) != m.end()){
                	// pattern = "abba", s = "dog cat cat fish"
                    if (m[pattern[i]] != v[i]) return false;
                }
                else{
                    // if any of the alphabet have'nt matched with string
                    if (st.count(v[i]) > 0) return false;
                    m[pattern[i]] = v[i];
                    st.insert(v[i]);
                }
            }

            return true;
        }
};

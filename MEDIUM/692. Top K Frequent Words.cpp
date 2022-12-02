/*Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 
Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]*/

class Solution {
public:
    
    // comparator
    
    struct comparator
    {
        bool operator() (pair<int, string>& a, pair<int, string>& b)
        {
            if(a.first == b.first)           // if frequency are equal put lexicographically greater element on top
            {
                return a.second < b.second;
            }
            else                            // if frequency are not equal put the elements on top which has less frequency
            {
                return a.first > b.first;
            }
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        
        // declare a map which store the frequency of words
        
        unordered_map<string, int> mp;
        
        for(auto word : words)
        {
            mp[word]++;
        }
        
        // declare a priority queue
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> pq;
        
        for(auto x : mp)
        {
            if(pq.size() < k)             // firstly push k elements into pq
            {
                pq.push({x.second, x.first});
            }
            else
            {
                if(pq.top().first < x.second || (pq.top().first == x.second && pq.top().second > x.first))
                {
                    pq.pop();
                    
                    pq.push({x.second, x.first});
                }
            }
        }
        
        // push all the elements from pq to res
        
        vector<string> res;
        
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            
            pq.pop();
        }
        
        // reverse the res
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};

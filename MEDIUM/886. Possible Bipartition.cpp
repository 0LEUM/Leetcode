/*We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 
Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].

Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= dislikes.length <= 104
dislikes[i].length == 2
1 <= dislikes[i][j] <= n
ai < bi
All the pairs of dislikes are unique.*/

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // typical Bipartition 
        if(dislikes.size()<1)   return true;
        
        bool b=true;
        unordered_map<int,unordered_set<int>> um;
        unordered_map<int,unordered_set<int>>::iterator umi;
        vector<int> vt(N+1,0);

        // Record Edges 
        for( int i=1; i<=N; i++){
            unordered_set<int> us;
            um.emplace( i, us);
        }
        
        for( int i=0; i<dislikes.size(); i++){
            umi=um.find(dislikes[i][0]);
            if(umi->second.find(dislikes[i][1])==umi->second.end())  umi->second.emplace(dislikes[i][1]);
            umi=um.find(dislikes[i][1]);
            if(umi->second.find(dislikes[i][0])==umi->second.end())  umi->second.emplace(dislikes[i][0]);
        }
        
        // DFS
        for( int i=1; i<=N; i++){
            if(vt[i]==0){// guranteed to visit all connected part 
                vt[i]=1;
                b=dfs( i, vt, um );
            }
            if(!b)  return false;
        }
        
        return b;
    }
    
    bool dfs( int i, vector<int>& vt, unordered_map<int,unordered_set<int>>& um ){
        bool b;
        unordered_map<int,unordered_set<int>>::iterator umi=um.find(i);
        
        for( unordered_set<int>::iterator usi=umi->second.begin(); usi!=umi->second.end(); usi++){
            if(vt[*usi]==0){
                vt[*usi]=vt[i]*-1;
                b=dfs( *usi, vt, um);
                if(!b)  return false;
            }else if(vt[*usi]==vt[i]){
                return false;
            }
        }
        
        return true;
    }
};

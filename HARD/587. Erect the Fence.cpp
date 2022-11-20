/*You are given an array trees where trees[i] = [xi, yi] represents the location of a tree in the garden.

You are asked to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed.

Return the coordinates of trees that are exactly located on the fence perimeter.

 
Example 1:

Input: points = [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
Output: [[1,1],[2,0],[3,3],[2,4],[4,2]]

Example 2:

Input: points = [[1,2],[2,2],[4,2]]
Output: [[4,2],[2,2],[1,2]]
 

Constraints:

1 <= points.length <= 3000
points[i].length == 2
0 <= xi, yi <= 100
All the given points are unique.*/

class Solution 
{
public:
    
    using tree = vector<int>;
    
    vector<tree> outerTrees(vector<tree>& trees) 
    {
        auto cross = [](tree& B, tree& A, tree& T) -> int
        {
            return (T[1]-B[1])*(B[0]-A[0]) - (B[1]-A[1])*(T[0]-B[0]);
        };
        
        sort(trees.begin(), trees.end());
        
        deque<tree> F;
        
        for (tree T : trees)
        {
            while (F.size() >= 2 and cross(F[F.size()-1],F[F.size()-2],T) < 0)
                F.pop_back();
            F.push_back(T);

            while (F.size() >= 2 and cross(F[0],F[1],T) > 0)
                F.pop_front();
            F.push_front(T);
        }
        
        set<tree> unique(F.begin(), F.end());
        return vector<tree>(unique.begin(), unique.end());
    }
};

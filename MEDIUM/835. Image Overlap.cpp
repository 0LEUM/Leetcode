/*You are given two images, img1 and img2, represented as binary, square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits left, right, up, and/or down any number of units. We then place it on top of the other image. We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated outside of the matrix borders are erased.

Return the largest possible overlap.


Example 1:

Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
Output: 3
Explanation: We translate img1 to right by 1 unit and down by 1 unit.

The number of positions that have a 1 in both images is 3 (shown in red).

Example 2:

Input: img1 = [[1]], img2 = [[1]]
Output: 1
Example 3:

Input: img1 = [[0]], img2 = [[0]]
Output: 0
 

Constraints:

n == img1.length == img1[i].length
n == img2.length == img2[i].length
1 <= n <= 30
img1[i][j] is either 0 or 1.
img2[i][j] is either 0 or 1.*/

class Solution 
{
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        size_t n = img1.size();
        
        // [1] first, we list coordinates (x,y) of 1-points in each image
        
        vector<pair<int32_t,int32_t>> idx1, idx2;
        
        for (int i = 0; i < n*n; i++)
            if (img1[i/n][i%n]) idx1.emplace_back(i/n, i%n);

        for (int j = 0; j < n*n; j++)
            if (img2[j/n][j%n]) idx2.emplace_back(j/n, j%n);
                
        // [2] second, we obtain translation vectors (i1-j1, i2-j2) needed to
        //    overlap each 1-point of img1 with each 1-point of img2, and count
        //    frequencies of these vectors;
        //    (note that here we make a 'flat' 2d array in order to use
        //    iterator-based max_element function later to find maximum)
        
        vector<int> tr_vecs(2*n * 2*n, 0);
        size_t vx, vy;
        for (auto [i1,i2] : idx1)
            for (auto [j1,j2] : idx2)
            {
                vx = (2*n+i1-j1) % (2*n);
                vy = (2*n+i2-j2) % (2*n);
                tr_vecs[vx*(2*n) + vy] += 1;
            }
        
        // [3] translation vector that has been encountered most of the time is
        //    the one that produces an overlap of the maximal number of points
        
        return *max_element(tr_vecs.begin(), tr_vecs.end());
    }
};

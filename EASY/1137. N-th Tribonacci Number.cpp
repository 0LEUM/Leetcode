/*The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 
Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537
 

Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.*/

class Solution {
public:
    int v[38]{0,1,1};
    // this vector v will store the tribonacci values as fasten up the process, it is special property of DP
    int tribonacci(int n) {
        if (n==0) return 0;
        if (v[n]) return v[n];
        // If value already calculated and stored we use it
        else return v[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        // we store the value as we go on calculating
    }
};

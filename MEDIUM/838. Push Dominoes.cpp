/*There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

 
Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
 

Constraints:

n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.*/

class Solution {
public:
    string pushDominoes(string s) {
    
    int n = s.size();
    int r=-1;
    
    for(int i=0;i<n;i++){
        
        if(s[i]=='L'){                                 
            if(r==-1){                                  //s[i]=='L' && r==-1
                for(int j=i-1;j>=0 && s[j]=='.';j--){   //update all dominoes to left beginning from j=i-1 to j>=0
                    s[j]='L';
                }
            }
            else{                                      //s[i]=='L' && r!=-1
                for(int j=r+1,k=i-1;j<k;j++,k--){      //update all dominoes lying between k=r+1 and j=i-1
                    s[j]='R';
                    s[k]='L';
                }
                r=-1;        //important step update r = -1
            }
        }
        else if(s[i]=='R'){                            //s[i]=='R' && r!=-1
            if(r!=-1){                                 //update all dominoes lying right to j=r+1 till i
                for(int j=r+1;j<i;j++){
                    s[j]='R';
                }
            }
            r=i;             //update r since r is found
        }
    }
    
    if(r!=-1){                     //if you have traversed complete string and r!=-1, then update all dominoes
        for(int j=r+1;j<n;j++) {   //beginning from r+1 to n to 'R'
            s[j]='R';
        }
    }
    
    return s;   
}
};

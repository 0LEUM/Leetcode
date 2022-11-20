/*Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 
Example 1:

Input: s = "1 + 1"
Output: 2

Example 2:

Input: s = " 2-1 + 2 "
Output: 3

Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.*/

class Solution {
public:
    int calculate(string s) {
        int result=0;
        int sum=0;
        int sign=1;
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                sum=s[i] -'0';
                while(i+1<n && isdigit(s[i+1]))
                {
                    sum = sum*10 + (s[i+1] -'0');
                    i++;
                }
                result+=sum*sign;
            }
            
            else if(s[i] == '+')
            {
                sign=1;
            }
            else if (s[i] == '-')
            {
                sign=-1;
            }
            else if (s[i] == '(')
            {
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
            }
            else if(s[i] == ')')
            {
                int xsign=st.top();
                st.pop();
                int xresult= st.top();
                st.pop();
                result=result*xsign + xresult;
            }
        }
        
        return result;
    }
};

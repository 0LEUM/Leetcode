/*A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

 
Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]

Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]

Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 

Constraints:

1 <= s.length <= 20
s consists of digits only.*/

class Solution {
public:
    bool check(string s){
        int n=s.size();
        //if the size of string is 1 that is always possible so return true
        if(n==1){
            return true;
        }
        //if we have length >3 or string starts with 0 return false
        if(n>3||s[0]=='0'){
            return false;
        }
        //we are converting string to integer to check if it is less than equalto 255
        int val=stoi(s);
        if(val>255){
            return false;
        }
        //return true at last
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        //we will store our ans in ans vector of strings
        vector<string>ans;
        //the max length of the ip address could be 12 as 255.255.255.255 so 
        //all the string s with size greater than 12 can have ans
        if(n>12){
            return ans;
        }
        //now we have our string of length 12 or less than 12 so now 
            //1. we have to spit the s in parts such that it satisfy the ip address conditions
            //2. if all 4 strings satisfy the condition we will push into ans vector
        
        for(int i=1;i<=3;i++){//for the length before first '.'
            for(int j=1;j<=3;j++){//for the length between first and second '.'
                for(int k=1;k<=3;k++){//for the length between second and third '.'
                    //checking condition if the last segment is of length 3 or less
                    if(i+j+k<n&&i+j+k+3>=n){
                        //dividing the s int substrings 
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(j+i,k);
                        string d=s.substr(i+j+k);
                        //if all the substring satisfy the check function condition 
                        //then we will push into ans vector 
                        if(check(a)&&check(b)&&check(c)&&check(d)){
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }
            }
        }
        //return the ans vector
        return ans;
    }
};

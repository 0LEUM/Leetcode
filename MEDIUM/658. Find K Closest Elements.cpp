/*Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 
Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 104
arr is sorted in ascending order.
-104 <= arr[i], x <= 104*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        auto closestElementToX = lower_bound(arr.begin(), arr.end(),x);
        int indexOfClosestElement = -1;
        if(closestElementToX==arr.end()) {
            indexOfClosestElement = arr.size()-1;
        } else {
            if(*closestElementToX == x) {
                indexOfClosestElement = closestElementToX - arr.begin();
               
            } else {
                
                int possibleClosestElementIndex = closestElementToX - arr.begin();
                indexOfClosestElement = possibleClosestElementIndex;
                if(possibleClosestElementIndex-1>=0 && abs(arr[indexOfClosestElement]-x)>= abs(arr[possibleClosestElementIndex-1]-x)) {
                    indexOfClosestElement = possibleClosestElementIndex-1;
                }
                if(possibleClosestElementIndex+1<arr.size() && abs(arr[indexOfClosestElement]-x)> abs(arr[possibleClosestElementIndex+1]-x)) {
                    indexOfClosestElement = possibleClosestElementIndex+1;
                }
                
            }
        }
        
        vector<int>kClosestElements;
        k--;
        int l = indexOfClosestElement-1, r = indexOfClosestElement+1;
        while(k>0) {
            if(l>=0 && r<arr.size()) {
                if(abs(arr[l]-x)<=abs(arr[r]-x)) {
     
                    l--;
                } else {
        
                    r++;
                }
            } else if(l>=0) {
                
                l--;
            } else {
                r++;
            }
            k--;
        }
        
        for(int i=l+1;i<r;i++){
            kClosestElements.push_back(arr[i]);
        }
        return kClosestElements;
    }
};

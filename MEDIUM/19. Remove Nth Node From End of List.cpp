/*Given the head of a linked list, remove the nth node from the end of the list and return its head.

 
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(n != 0) {
            fast = fast->next;
            n--;
        }
        
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        
        if(slow == head && fast == NULL) return head->next;
        
        slow->next = slow->next->next;
        return head;
    }
};

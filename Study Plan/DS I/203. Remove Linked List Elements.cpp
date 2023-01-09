/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 
Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 104].
1 <= Node.val <= 50
0 <= val <= 50*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void deleteAtEnd(ListNode*& head){
        ListNode* prev= head;
        if (head==NULL || head->next==NULL)return;
        while (prev->next){
            if (prev->next->next == NULL){
                prev->next = NULL;
                return;
            }
            prev= prev->next;
        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr= head;
        while (curr){
            if (curr->val==val){
                //head
                if (curr == head){
                    head= head->next;
                    curr= curr->next;
                }
                //last node
                else if (curr->next == NULL){
                    deleteAtEnd(head);
                    curr= NULL;
                }
                // other nodes
                else{
                    curr->val= curr->next->val;
                    curr->next= curr->next->next;
                }

            }
            else{
                curr = curr->next;
            }
        }

        return head;
    }
};

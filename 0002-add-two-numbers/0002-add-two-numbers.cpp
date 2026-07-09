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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while(l1!= NULL || l2 != NULL){
            int val1 = 0;
            int val2 = 0;
            if(l1==NULL){
                val1 = 0;
            }
            else{
                val1 = l1->val;
            }
            if(l2 == NULL){
                val2 = 0;
            }
            else{
                val2 = l2->val;
            }

            int sum = val1+val2+carry;
            carry = sum/10;
            int digit = sum %10;
            curr->next = new ListNode(digit);
            curr = curr->next;
            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2= l2->next;
            
        }
        if(carry>0){
            curr->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
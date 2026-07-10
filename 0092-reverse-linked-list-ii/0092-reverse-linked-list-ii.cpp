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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for(int i = 0; i<left-1; i++){
            prev = prev->next;
        }
        
        ListNode* next = NULL;
        ListNode* pi = NULL;
        ListNode* curr = prev->next;
        ListNode* tail = curr;

        for(int i = 0; i<right-left+1; i++){
            next = curr->next;
            curr->next = pi;
            pi = curr;
            curr= next;
        }
        prev->next = pi;
        tail->next = curr;
        return dummy->next;
    }
};
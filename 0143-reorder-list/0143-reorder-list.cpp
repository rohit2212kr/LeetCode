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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;

        // find middle
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;

        // reverse the 2nd half
        ListNode* p = NULL;
        ListNode* nxt = NULL;
        while(slow != NULL){
            nxt = slow->next;
            slow->next = p;
            p = slow;
            slow = nxt;
        }

        // merge both halves
        ListNode* h1 = head;
        ListNode* a = NULL;
        ListNode* b = NULL;
        ListNode* tail = head;

        while(h1 != NULL && p != NULL){
            a = h1->next;
            b = p->next;
            h1->next = p;
            h1 = a;
            p->next = h1;
            tail = (h1 != NULL) ? h1 : p;
            p = b;
        }

        if(p != NULL){
            tail->next = p;
        }
    }
};
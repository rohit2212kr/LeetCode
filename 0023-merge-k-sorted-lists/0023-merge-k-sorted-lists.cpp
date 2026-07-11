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
    ListNode* merge2List(ListNode* L1, ListNode* L2){
        if(L1 == NULL) return L2;
        if(L2 == NULL) return L1;

        if(L1->val <= L2->val){
            L1->next = merge2List(L1->next, L2);
            return L1;
        }
        else{
            L2->next = merge2List(L1, L2->next);
            return L2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;

        int k = lists.size();

        while(k > 1){
            int newK = 0;

            for(int i = 0; i < k; i += 2){
                if(i + 1 < k){
                    lists[newK] = merge2List(lists[i], lists[i+1]);
                } else {
                    lists[newK] = lists[i];
                }
                newK++;
            }

            k = newK;
        }

        return lists[0];
    }
};
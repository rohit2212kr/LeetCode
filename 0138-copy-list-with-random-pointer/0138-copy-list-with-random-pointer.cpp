/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        
        Node* curr = head;
        Node* prev = NULL;
        Node* newhead = NULL;

        while(curr!= NULL){
            Node* temp = new Node(curr->val);
            mp[curr] = temp;
            if(newhead == NULL){
                newhead = temp;
                prev= newhead;

            }
            else{
                prev->next = temp;
                prev = temp;
            }
            curr = curr->next;
        }

        //random assign
        curr = head;
        Node* newcurr = newhead;
        while(curr!= NULL){
            if(curr->random == NULL){
                newcurr->random = NULL;
            }
            else{
                newcurr->random = mp[curr->random];
            }
            curr = curr->next ;
            newcurr = newcurr ->next;

        }
        return newhead;

    }
};
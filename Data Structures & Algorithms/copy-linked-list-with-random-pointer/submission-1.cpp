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
        if(!head) return nullptr;

        // insert copied nodes
        Node *curr = head;
        while(curr != NULL){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        // set random pointers
        curr = head;
        while(curr){
            if(curr -> random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // separate lists
        Node* dummy = new Node(-1);
        Node* copyCurr = dummy;
        curr = head;

        while(curr){
            // making original list again
            Node* copy = curr->next;
            curr -> next = copy -> next;

            // creating a copy list
            copyCurr -> next = copy;
            copyCurr = copy;

            curr = curr->next;
        }

        return dummy->next;
    }
};

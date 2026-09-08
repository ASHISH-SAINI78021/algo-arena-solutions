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
        if (head == NULL) return NULL;
        Node* curr = head;
        Node* dummy = new Node(0);
        Node* temp = dummy;
        while (curr != NULL){
            Node* next = curr->next;
            Node* temp = new Node(curr->val);
            curr->next = temp;
            temp->next = next;
            curr = next;
        }

        curr = head;
        while (curr != NULL){
            Node* temp = curr->next;
            if (curr && curr->random) temp->random = curr->random->next;
            curr = temp->next;
        }

        curr = head;
        while (curr != NULL){
            Node* next = curr->next;
            temp->next = next;
            curr->next = next->next;
            curr = curr->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
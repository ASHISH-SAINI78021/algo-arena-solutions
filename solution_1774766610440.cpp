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
    int length(ListNode* head){
        int len = 0;
        while (head != NULL){
            len++;
            head = head->next;
        }

        return len;
    }
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return NULL;
        int n = length(head);
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }

        return (n & 1) ? prev : slow;
    }
};



// example : 1 2 3 4 5 6
// length -> odd -> 5 -> (n + 1)/2
// length -> even -> 6 -> (n/2 + 1) = pos

// slow pointer approach
// length -> odd -> 
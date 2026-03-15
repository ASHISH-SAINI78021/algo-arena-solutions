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
        if (head == NULL) return head;
        int len = length(head);
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }

        return (len & 1) ? prev : slow;
    }
};
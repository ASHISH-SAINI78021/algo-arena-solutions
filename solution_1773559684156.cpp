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
            head = head->next;
            len++;
        }

        return len;
    }
    ListNode* deleteFromBegining(ListNode* head){
        if (head == NULL) return head;
        else {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }
    }
    ListNode* removeFromEnd(ListNode* head){
        if (head == NULL) return head;
        else {
            ListNode* prev = NULL;
            ListNode* temp = head;
            while (temp->next != NULL){
                prev = temp;
                temp = temp->next;
            }
            if (prev) prev->next = NULL;
            delete temp;
            return head;
        }
    }
    ListNode* deleteFromPosition(ListNode* head, int pos, int len){
        if (pos == 1) return deleteFromBegining(head);
        if (pos == len) return removeFromEnd(head);
        int i = 1;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (i < pos && temp != NULL){
            prev = temp;
            temp = temp->next;
            i++;
        }
        // cout << temp->val << endl;
        if (prev) prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        int len = length(head);
        head = deleteFromPosition(head, len - n + 1, len);
        return head;
    }
};
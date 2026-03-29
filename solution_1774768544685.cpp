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
    ListNode* removeFromTheBegining(ListNode* head){
        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    ListNode* removeFromTheEnd(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp->next != NULL){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        delete temp;
        return head;
    }
    ListNode* removeFromPositionN(ListNode* head, int n, int len){
        if (n == 1) return removeFromTheBegining(head);
        if (n == len) return removeFromTheEnd(head);
        int i = 1;
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (i < n && i < len && temp != NULL){
            prev = temp;
            temp = temp->next;
            i++;
        }

        prev->next = temp->next;
        temp->next = NULL;
        delete temp;

        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        int len = length(head);
        head = removeFromPositionN(head, len - n + 1, len);
        return head;
    }
};

// len - n + 1 th from the begining
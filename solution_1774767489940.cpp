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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while (temp1 != NULL && temp2 != NULL){
            if (temp1->val > temp2->val){
                curr->next = temp2;
                curr = curr->next;
                temp2 = temp2->next;
            }
            else {
                curr->next = temp1;
                curr = curr->next;
                temp1 = temp1->next;
            }
        }

        while (temp1 != NULL){
            curr->next = temp1;
            curr = curr->next;
            temp1 = temp1->next;
        }
        while (temp2 != NULL){
            curr->next = temp2;
            curr = curr->next;
            temp2 = temp2->next;
        }

        return dummy->next;
    }
};
// i
// 1 2 4 i-> arr1
// 1 3 4 -> arr2
//    j
// 1 1 2 3 4 4


// arr[i] > arr[j] -> ans[arr[j]]
// else ans[arr[i]]
// while (j < n) ans[arr[j]]
// while (i < n) ans[arr[i]];

// ans[i]
// ans -> linked list -> head of the linked list.


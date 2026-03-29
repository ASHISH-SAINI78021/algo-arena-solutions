/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
            if (slow == fast) return true;
        }

        return false;
    }
};

// key value
// if (mp.find(node) == mp.end())
// mp[node] = node->next;
// else return true;

// 3 -> 2
// 2 -> 0
// 0 -> -4
// -4 -> 2
// 2 -> return true;

// slow fast pointer approach
// slow = head
// fast = head
// slow = by one node
// fast = by two nodes in every iteration.

// if (there is a cycle) slow == fast -> true
// else fast != NULL -> false;
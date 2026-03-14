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
class Compare {
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        if (n == 1) return lists[0];
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (int i = 0; i < n; i++){
            ListNode* head = lists[i];
            if (head) pq.push(head);
        }

        while (!pq.empty()){
            auto front = pq.top(); pq.pop();
            curr->next = front;
            curr = front;
            if (front->next) pq.push(front->next);
        }

        return dummy->next;
    }
};
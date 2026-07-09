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
    bool operator()(ListNode* &a, ListNode* &b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return NULL;
        if (n == 1) return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;


        for (int i = 0; i < n; i++){
            ListNode* temp = lists[i];
            if (temp) pq.push(lists[i]);
        }

        while (!pq.empty()){
            auto temp = pq.top(); pq.pop();
            curr->next = temp;
            curr = curr->next;
            if (temp->next) pq.push(temp->next);
        }

        return dummy->next;
    }
};


// Time Complexity : O(nlogk)
// Space Complexity : O(k)
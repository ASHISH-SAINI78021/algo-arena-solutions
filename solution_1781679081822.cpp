class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for (auto it : stones) pq.push(it);

        while (pq.size() > 1){
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            if (first == second){
                continue;
            }
            else {
                pq.push(abs(second - first));
            }
        }

        if (pq.empty()) return 0;
        else return pq.top();
    }
};
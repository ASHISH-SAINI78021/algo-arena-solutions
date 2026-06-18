class KthLargest {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n && i < k; i++) pq.push(nums[i]);
        for (int i = k; i < n; i++){
            if (nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        int n = pq.size();
        if (k > n) pq.push(val);
        else if (val > pq.top()){
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
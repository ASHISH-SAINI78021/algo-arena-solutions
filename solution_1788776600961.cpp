class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty()) left.push(num);
        else if (left.top() >= num) left.push(num);
        else right.push(num);

        // Rebalance
        if (abs((int)left.size() - (int)right.size()) > 1){
            if (left.size() > right.size() + 1){
                right.push(left.top()); left.pop();
            }
            else if (left.size() + 1 < right.size()){
                left.push(right.top()); right.pop();
            }
        }
    }
    
    double findMedian() {
        int size1 = left.size();
        int size2 = right.size();
        if (size1 > size2) return 1.0*left.top();
        else if (size1 < size2) return 1.0*right.top();
        else return (left.top() + right.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (left.empty()) left.push(num);
        else if (!left.empty() && left.top() >= num) left.push(num);
        else right.push(num);

        if (left.size() > right.size() + 1){
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size() + 1){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        double num1 = (!left.empty()) ? left.top() : 0;
        double num2 = (!right.empty()) ? right.top() : 0;
       
       if (left.size() == right.size()) return (num1 + num2)/2.0;
       else if (left.size() > right.size()) return num1;
       else return num2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
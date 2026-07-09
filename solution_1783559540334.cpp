class MinStack {
public:
    vector<int> arr;
    vector<int> mini;
    MinStack() {
        
    }
    
    void push(int value) {
        arr.push_back(value);
        if (mini.empty()) mini.push_back(value);
        else {
            if (mini.back() >= value) mini.push_back(value);
        }
    }
    
    void pop() {
        if (arr.empty()) return ;
        if (!mini.empty() && arr.back() == mini.back()){
            mini.pop_back();
            arr.pop_back();
        }
        else arr.pop_back();
    }
    
    int top() {
        if (arr.empty()) return 0;
        return arr.back();
    }
    
    int getMin() {
        if (mini.empty()) return 0;
        return mini.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
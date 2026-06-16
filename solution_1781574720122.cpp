class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int, int> pr = {price, 1};
        while (!st.empty() && price >= st.top().first){
            auto temp = st.top(); st.pop();
            pr.second += temp.second;
        }
        st.push(pr);

        return pr.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
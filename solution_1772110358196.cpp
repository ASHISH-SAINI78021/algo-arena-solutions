class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        set<int> st(a.begin(), a.end());
        for (auto it : b) st.insert(it);
        
        vector<int> ans;
        for (auto it : st){
            ans.push_back(it);
        }
        
        return ans;
    }
};
class Compare {
    public:
    bool operator()(auto &a, auto &b){
        return a.first > b.first;
    }
};
class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        using T = pair<int ,pair<int, vector<int>>>;
        priority_queue<T, vector<T>, Compare> pq;
        
        for (int i = 0; i < n; i++){
            pq.push({mat[i][0], {0, mat[i]}});
        }
        
        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int element = top.first;
            ans.push_back(element);
            int index = top.second.first;
            vector<int> arr = top.second.second;
            int size = arr.size();
            if (index + 1 < size) pq.push({arr[index + 1], {index + 1, arr}});
        }
        
        return ans;
    }
};
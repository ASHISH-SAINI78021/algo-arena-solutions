class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);

        queue<int> q;

        for (int i = 0; i < n; i++){
            if (color[i] == -1){
                q.push(i);
                color[i] = 0;
                while (!q.empty()){
                    auto front = q.front(); q.pop();
                    for (auto it : adj[front]){
                        if (color[front] == color[it]) return false;
                        else if (color[it] == -1){
                            color[it] = 1 - color[front];
                            q.push(it);
                        }
                    }
                }
            }
        }

        return true;
    }
};
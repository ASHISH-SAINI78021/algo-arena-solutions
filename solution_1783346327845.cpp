class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v, -1);
        queue<int> q;

        for (int i = 0; i < v; i++){
            if (color[i] == -1){
                q.push(i);
                while (!q.empty()){
                    auto front = q.front(); q.pop();
                    for (auto it : graph[front]){
                        if (color[it] == -1){
                            q.push(it);
                            color[it] = 1 - color[front];
                        }
                        else if (color[it] == color[front]){
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
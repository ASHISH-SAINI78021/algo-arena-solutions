class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        queue<int> q;
        
        for (int i = 0; i < V; i++){
            if (color[i] == -1){
                q.push(i);
                color[i] = 0;
                while (!q.empty()){
                    auto front = q.front(); q.pop();
                    for (auto it : graph[front]){
                        if (color[it] == -1){
                            q.push(it);
                            color[it] = 1 - color[front];
                        }
                        else if (color[it] == color[front]) return false;
                    }
                }
            }
        }

        return true;
    }
};
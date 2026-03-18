class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> adj[numCourses];
        int count = 0;

        for (int i = 0; i < n; i++){
            int u = arr[i][1];
            int v = arr[i][0];
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses);
        queue<int> q;
        for (int i = 0; i < numCourses; i++){
            for (auto it : adj[i]){
                indegree[it]++;
            }
        }

        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()){
            auto front = q.front(); q.pop();
            count++;
            for (auto it : adj[front]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }


        return count == numCourses;
    }
};
class Solution {
  public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        queue<char> q;
        string ans;
        
        for (auto word : words){
            for (auto it : word) indegree[it] = 0;
        }
        
        for (int i = 1; i < n; i++){
            string word1 = words[i - 1];
            string word2 = words[i];
            int len = min(word1.length(), word2.length());
            bool found = false;
            for (int j = 0; j < len; j++){
                if (word1[j] != word2[j]){
                    found = true;
                    if (adj[word1[j]].find(word2[j]) == adj[word1[j]].end()){
                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    break ;
                }
            }
            
            if (!found && word1.size() > word2.size()) return "";
        }
        
        for (auto it : indegree){
            if (it.second == 0){
                q.push(it.first);
                // cout << it.first << " ";
            }
        }
        
        while (!q.empty()){
            auto front = q.front(); q.pop();
            ans += front;
            for (auto it : adj[front]){
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        if (indegree.size() != ans.size()) return "";
        // cout << ans << endl;
        
        return ans;
        
    }
};
class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        queue<char> q;
        string ans = "";

        // Insert every unique character
        for (auto &word : words) {
            for (char ch : word) {
                indegree[ch] = 0;
            }
        }

        // Build graph
        for (int i = 1; i < n; i++) {
            string word1 = words[i - 1];
            string word2 = words[i];

            int len = min(word1.size(), word2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {

                    // Avoid duplicate edges
                    if (adj[word1[j]].find(word2[j]) == adj[word1[j]].end()) {
                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }

                    found = true;
                    break;
                }
            }

            // Invalid prefix case
            if (!found && word1.size() > word2.size())
                return "";
        }

        // Push all indegree 0 characters
        for (auto it : indegree) {
            if (it.second == 0)
                q.push(it.first);
        }

        // Kahn's Algorithm
        while (!q.empty()) {
            char front = q.front();
            q.pop();

            ans += front;

            for (char it : adj[front]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        // Cycle exists
        if (ans.size() != indegree.size())
            return "";

        return ans;
    }
};
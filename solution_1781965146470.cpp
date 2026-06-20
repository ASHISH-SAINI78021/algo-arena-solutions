class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       int size = tasks.size(); 
       unordered_map<int, int> mp;
       for (int i = 0; i < size; i++) mp[tasks[i]]++;

        int maxFreq = 0;
        for (auto it : mp) maxFreq = max(maxFreq, it.second);
        int count = 0;
        for (auto it : mp){
            if (maxFreq == it.second) count++;
        }
        
        int ans = n*(maxFreq - 1) + maxFreq + count - 1;

        if (size > ans) return size;

        return ans;
    }
};
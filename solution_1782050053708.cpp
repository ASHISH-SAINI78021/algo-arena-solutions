class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        string ans = ""; 
        unordered_map<char, int> mp;
        priority_queue<pair<int, int>> pq;
        for (auto it : s) mp[it]++;
        for (auto it : mp) pq.push({it.second, it.first});

        while (pq.size() > 1){
            auto top1 = pq.top();pq.pop();
            auto top2 = pq.top(); pq.pop();
            char char1 = top1.second;
            char char2 = top2.second;
            int element1 = top1.first;
            int element2 = top2.first;
            ans += char1;
            ans += char2;
            element1--;
            element2--;
            if (element1 > 0) pq.push({element1, char1});
            if (element2 > 0) pq.push({element2, char2});
        }
        
        if (!pq.empty()){
            if (pq.size() == 1 && pq.top().first == 1){
                ans += pq.top().second;
                return ans;
            }
            else return "";
        }

        return ans;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        using T = pair<int, string>;
        queue<T> q;
        if (beginWord.length() != endWord.length()) return 0;
        if (st.find(endWord) == st.end()) return 0;
        q.push({1, beginWord});
        int ans = 0;
        
        while (!q.empty()){
            auto front = q.front(); q.pop();
            int steps = front.first;
            string word = front.second;
            if (word == endWord) return steps;
            for (int i = 0; i < word.length(); i++){
                string str = word;
                for (char ch = 'a'; ch <= 'z'; ch++){
                    str[i] = ch;
                    if (st.find(str) != st.end()){
                        q.push({1 + steps, str});
                        st.erase(str);
                    }
                }
            }
        }

        // T.C = O(word.length()*word.length() * wordList.size())
        // S.C = O(wordList.size()*word.length())

        return 0;
    }
};
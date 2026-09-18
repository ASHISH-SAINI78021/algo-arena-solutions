class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.length() != endWord.length()) return 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;
        using T = pair<int, string>;
        queue<T> q;
        q.push({1, beginWord});

        while (!q.empty()){
            auto front = q.front(); q.pop();
            int steps = front.first;
            string word = front.second;

            if (word == endWord) return steps;

            for (int i = 0; i < word.length(); i++){
                for (char ch = 'a'; ch <= 'z'; ch++){
                    string str = word;
                    str[i] = ch;
                    if (st.find(str) != st.end()){
                        q.push({steps + 1, str});
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
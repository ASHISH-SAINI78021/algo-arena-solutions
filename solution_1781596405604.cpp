class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        stack<char> st;
        string ans;
        int freq[26] = {0};
        bool used[26] = {false};

        for (auto ch : s) freq[ch - 'a']++;

        for (int i = 0; i < n; i++){
            freq[s[i] - 'a']--;
            if (used[s[i] - 'a']) continue;
            while (!st.empty() && st.top() > s[i] && freq[st.top() - 'a']){
                used[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            used[s[i] - 'a'] = true;
        }

        while (!st.empty()){
            ans += st.top(); st.pop();
        }
        
        reverse(ans.begin(), ans.end());

        return ans;
    }
}; 
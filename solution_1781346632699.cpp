class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans;
        stack<string> st;

        string temp = "";
        for (int i = 0; i < n; i++){
            if (s[i] != ' ') temp += s[i];
            else {
                if (!temp.empty()) st.push(temp);
                temp.clear();
            }
        }

        if (!temp.empty()) st.push(temp);

        while (!st.empty()){
            ans += st.top(); st.pop();
            ans += " ";
        }

        ans.pop_back();

        return ans;
    }
};
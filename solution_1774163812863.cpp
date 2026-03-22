class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans = "";
        stack<char> st;

        for (int i = 0; i < n; i++){
            while (!st.empty() && k && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (!st.empty() && k){
            st.pop();
            k--;
        }

        while (!st.empty()){
            ans += st.top(); st.pop();
        }
        int start = ans.length() - 1;
        while (!ans.empty() && ans[ans.length() - 1] == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());

        return (ans.empty()) ? "0" : ans;
    }
};


// num = 1432219    k = 3
// 4 9 9 9 9 9 -1

// Logic
// 4 > 3 -> remove 4
// 3 > 2 -> remove 3
// 2 > 1 -> remove 2

// step1:- remove above elements 
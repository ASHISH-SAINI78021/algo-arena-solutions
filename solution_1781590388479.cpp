class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string ans = "";
        stack<char> st;
        if (k >= n) return "0";
        
        for (int i = 0; i < n; i++){
            while (!st.empty() && k > 0 && st.top() > num[i]){
                st.pop(); k--;
            }
            st.push(num[i]);
        }

        while (!st.empty()){
            ans += st.top(); st.pop();
        }

        if (ans == "0") return "0";

        for (int i = ans.size() - 1; i >= 0; i--){
            if (ans[i] == '0') ans.pop_back();
            else break ;
        }
        reverse(ans.begin(), ans.end());

        while (!ans.empty() && k--) ans.pop_back();

        

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
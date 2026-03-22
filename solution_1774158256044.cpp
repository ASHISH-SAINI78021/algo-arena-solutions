class Solution {
public:
    bool isOperator(string s){
        if (s == "+" || s == "-" || s == "*" || s == "/") return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        int ans = 0;

        for (int i = 0; i < n; i++){
            if (isOperator(tokens[i])){
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();
                if (tokens[i] == "*"){
                    int result = op1 * op2;
                    st.push(result);
                }
                else if (tokens[i] == "+"){
                    int result = op1 + op2;
                    st.push(result);
                }
                else if (tokens[i] == "-"){
                    int result = op2 - op1;
                    st.push(result);
                }
                else {
                    int result = op2/op1;
                    st.push(result);
                }
            }
            else {
                int result = stoi(tokens[i]);
                st.push(result);
            }
        }

        return st.top();
    }
};
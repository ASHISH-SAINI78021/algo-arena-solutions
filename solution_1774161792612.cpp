class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        string curr = "";
        stack<int> countStack;
        stack<string> stringStack;
        int num = 0;
        for (auto c : s){
            if (isdigit(c)){
                num = num*10 + (c - '0');
            }
            else if (c == '['){
                countStack.push(num);
                stringStack.push(curr);
                curr = "";
                num = 0;
            }
            else if (c == ']'){
                int repeat = countStack.top(); countStack.pop();
                string prev = stringStack.top(); stringStack.pop();
                string temp = "";
                for (int i = 0; i < repeat; i++){
                    temp += curr;
                }
                curr = prev + temp;
            }
            else curr += c;
        }

        return curr;
    }
};
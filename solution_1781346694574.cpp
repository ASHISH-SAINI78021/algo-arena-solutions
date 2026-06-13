class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for (int i = n - 1; i >= 0; i--){
            if ((num[i] - '0') & 1) return num;
            else num.pop_back();
        }

        return "";
    }
};

// num = 52
// substrings and indiv odd one -> is it a largest one
// o(n3) -> time complexity
// o(1) -> constant space complexity



// num = 35427 
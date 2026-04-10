class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 1) return s;
        int maxi = 0;
        string ans = "";
        int startingIndex = -1;

        for (int i = 0; i < n; i++){
            int start = i;
            int end = i;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (end - start + 1 > maxi){
                    maxi = max(maxi, end - start + 1);
                    startingIndex = start;
                }
                start--;
                end++;
            }
            start = i;
            end = i + 1;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (end - start + 1 > maxi){
                    maxi = max(maxi, end - start + 1);
                    startingIndex = start;
                }
                start--;
                end++;
            }
        }

        return s.substr(startingIndex, maxi);
    }
};

// babad

// a , aba
// odd one

// even length
// aa, abba
// i,j
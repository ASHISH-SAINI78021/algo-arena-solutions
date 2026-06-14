class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        int maxi = 0;
        int startIndex = -1;

        for (int i = 0; i < n; i++){
            int start = i; int end = i;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (end - start + 1 > maxi){
                    maxi = end - start + 1;
                    startIndex = start;
                }
                start--; end++;
            }
            start = i;
            end = i + 1;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (end - start + 1 > maxi){
                    maxi = end - start + 1;
                    startIndex = start;
                }
                start--; end++;
            }
        }

        ans = s.substr(startIndex, maxi);

        return ans;
    }
};

// babad

// a , aba
// odd one

// even length
// aa, abba
// i,j
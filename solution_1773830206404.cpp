class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxi = 0;
        int startingIndex;

        for (int i = 0; i < n; i++){
            int start = i;
            int end = i;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (end - start + 1 > maxi){
                    maxi = end - start + 1;
                    startingIndex = start;
                }
                start--;
                end++;
            }
            start = i;
            end = i + 1;
            while (start >= 0 && end < n && s[start] == s[end]){
                if (end - start + 1 > maxi){
                    maxi = end - start + 1;
                    startingIndex = start;
                }
                start--;
                end++;
            }
        }

        return s.substr(startingIndex, maxi);
    }
};
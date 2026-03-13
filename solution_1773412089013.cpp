class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l = 0; int r = 0;
        int maxf = 0;

        unordered_map<char, int> mp;
        int maxi = 0;

        while (r < n){
            mp[s[r]]++;
            maxf = max(maxf, mp[s[r]]);
            while (r - l + 1 - maxf > k){
                mp[s[l]]--;
                if (mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            maxi = max(maxi, r - l + 1);
            r++;
        }

        return maxi;
    }
};


// s = ABAB    k = 2
// output -> AAAA -> 4
//        -> BBBB -> 4


// s = AABABBA   k = 1
//     AABBBBA -> 4


// AAAABBBC  k = 3 
// output -> 7

/// Expected Time complexity: O(n2) ~ O(n3)
/// Expected Space Complexity: O(n*3)


// Another approach -> optimal one
// s = ABAB    k = 2
// l = 0 r = 0 
// unordered_map<char, int> mp -> O(1);
// window size = r - l + 1 -> 1
// maxF = 2;
// r - l + 1 - maxf <= k
// 3 - 2 <= 2
// 1 <= 2

// r - l + 1 - maxf > k
// ABACD

// becomes 
// Space Complexity: O(n)
// Time complexity: O(n)




// s = ABAB   k = 2
// case1
// BBBB   -> 4
// case2
// AAAA  -> k = 2
// -> 4
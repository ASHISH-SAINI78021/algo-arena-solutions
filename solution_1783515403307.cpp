class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;

        // Store frequency of characters in t
        for (char ch : t)
            mp[ch]++;

        int left = 0;
        int required = t.size();

        int start = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < s.size(); right++) {

            // If current character is needed
            if (mp[s[right]] > 0)
                required--;

            // Decrease frequency
            mp[s[right]]--;

            // Window is valid
            while (required == 0) {

                // Update minimum window
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                mp[s[left]]++;

                // If this character becomes required again
                if (mp[s[left]] > 0)
                    required++;

                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
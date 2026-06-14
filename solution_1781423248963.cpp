class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> s1Count(26 , 0);
        vector<int> s2Count(26 , 0);
        
        for (int i = 0; i < n1; i++){
            s1Count[s1[i] - 'a']++;
        }

        int l = 0;
        int r = 0;

        for (r = 0; r < n2; r++){
            s2Count[s2[r] - 'a']++;
            if (r >= n1){
                s2Count[s2[r - n1] - 'a']--;
            }
            if (s1Count == s2Count){
                return true;
            }
        }

        return false;
    }
};
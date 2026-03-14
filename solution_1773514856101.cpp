class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int count = 0;
        int maxi = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < n){
            if (start[i] < end[j]){
                count++;
                i++;
            }
            else {
                j++;
                count--;
            }
            maxi = max(maxi, count);
        }
        
        return maxi;
    }
};
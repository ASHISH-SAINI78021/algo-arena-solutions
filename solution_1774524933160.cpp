class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n = start.size();
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int rooms = 0;
        int maxi = 0;
        int i = 0;
        int j = 0;
        while (i < n && j < n){
            if (start[i] < end[j]){
                rooms++;
                i++;
            }
            else {
                rooms--;
                j++;
            }
            maxi = max(maxi, rooms);
        }
        
        return maxi;
    }
};

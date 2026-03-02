class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        if (n == 1){
            if (nums[0] == target) return true;
            return false;
        }

        while (start <= end){
            int mid = start + (end - start)/2;
            if (nums[mid] == target){
                return true;
            }
            if (nums[mid] == nums[start] && nums[mid] == nums[end]){
                start++;
                end--;
                continue ;
            }

            if (nums[mid] >= nums[start]){
                // left part is sorted
                if (target >= nums[start] && target <= nums[mid]){
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else {
                // right part is sorted
                if (target >= nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }
                else end = mid - 1;
            }
        }


        return false;
    }
};
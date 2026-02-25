class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        if (n == 1) return ;
        for (int i = 0; i < n; i++){

            if (nums[i] == 0){
                index = i;
                break;
            }
        }

        for (int i = index; i < n; i++){
            if (nums[i] != 0){
                swap(nums[i], nums[index++]);
            }
        }
    }
};
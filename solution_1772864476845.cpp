class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0;
        int end = n*m - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            int row = mid/m;
            int col = mid % m;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] > target) end = mid - 1;
            else start = mid + 1;
        }


        return false;
    }
};


// each row is sorted
// arr[i - 1][m - 1] < arr[i][0] (always)
// target -> if it is in matrix -> true else false

// Example
// 1  3  5  7           target = 3
// 10 11 16 20
// 23 30 34 60

// Brute force -> linear search -> O(n*m)
// Optimal Approach -> B.S -> O(logn * logm) -> O(log(n*m))
// S.C -> O(1)

// flatten view
// 1 3 5 7 10 11 16 20 23 30 34 60
// row = mid / m
// col = mid % m

// constraints
// -> Our solution will work according to given constraints
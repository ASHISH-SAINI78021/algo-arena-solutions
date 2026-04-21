#include <bits/stdc++.h>
using namespace std;

void rotateByOne(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {
        return; // No rotation needed for empty or single-element arrays
    }
    int temp = arr[0]; // Store the first element
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    arr[n - 1] = temp; // Place the stored first element at the end
}

int main() {
    int n;
    cin >> n; // Input the size of the array
    vector<int> arr(n); // Allocate memory for the array
    for(int i=0; i<n; i++) cin >> arr[i]; // Input the elements of the array
    rotateByOne(arr);
    for(int i=0; i<n; i++) cout << arr[i] << (i==n-1 ? "" : " "); // Output the rotated array
    cout << endl;
    return 0;
}

// Input for terminal
// 5 // Number of elements in the array
// 1 2 3 4 5 // Elements of the array< endl;
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left = 0, right = n; // 注意right == 1
        int mid = 0;
        while (left < right) {
            mid = (left + right) /2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] > target) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        
        return left;
    }
};

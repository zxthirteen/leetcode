class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        
        // find left
        int left = 0, right = n;
        int mid = 0;
        while (left < right) {
            mid = (left + right) /2;
            if (A[mid] < target) {
                left = mid +1;
            } else {
                right = mid;
            }
        }
        
        if (A[left] != target) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else {
            res.push_back(left);
        }
        
        // important optimized: left needn't be set to 1
        // find the next one of the target nums:
        // e.x. [12234,2] find the '3'
        right = n;
        mid = 0;
        while (left < right) {
            mid = (left + right) /2;
            if (A[mid] > target) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        
        res.push_back(left-1);
        return res;
    }
};

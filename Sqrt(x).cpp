class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long left = 0, right = x;
        long long mid = 0;
        
        while (left <= right) {
            mid = left + (right - left)/2;
            if (mid * mid <= x && (mid+1) * (mid+1) > x)
                break;
            else if (mid * mid < x)
                left = mid+1;
            else 
                right = mid-1;
        }
        
        return mid;
    }
};

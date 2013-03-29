class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        int p = n-2;
        while (p >= 0) {
            if (num[p] < num[p+1])
                break;
            p--;
        }
        if (p < 0) {
            sort(num.begin(), num.end());
            return;
        }
        
        int tmp = n-1;
        while (num[tmp] <= num[p]) tmp--;
        swap(num[p], num[tmp]);
        sort(num.begin()+p+1, num.end());
    }
};

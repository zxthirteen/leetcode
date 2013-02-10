class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;
        res.push_back(0);
        if (n == 0) return res;
        res.push_back(1);
        
        int p = 1;
        for (int i = 1; i < n; i++) {
            p *= 2;
            for (int k = res.size() -1; k >= 0; k--) {
                res.push_back(res[k]);
                res.back() += p;
            }
        }
        
        return res;
    }
};

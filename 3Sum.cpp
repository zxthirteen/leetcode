class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        vector<vector<int> > res;
        
        int n = num.size();
        for (int i = 0; i < n-2; i++) {
            if (i > 0 && num[i] == num[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while (j < k) {
                while (j > i+1 && j < k && num[j] == num[j-1]) j++;
                while (k < n-1 && j < k && num[k] == num[k+1]) k--;
                if (j == k) break;
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> oneres;
                    oneres.push_back(num[i]);
                    oneres.push_back(num[j]);
                    oneres.push_back(num[k]);
                    res.push_back(oneres);
                    j++;
                } else if(sum < 0){
                    j++;
                } else k--;
                
            }
        }
        
        return res;
    }
};

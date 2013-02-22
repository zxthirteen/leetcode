class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        vector<vector<int> > ans;
        ans.push_back(num);
        if (num.size() == 1) return ans;
        
        int find = -1;
        
        while (true) {
            find = -1;
            for (int i = num.size()-2; i >= 0; i--) {
                if (num[i] < num[i+1]) {
                    find = i;
                    break;
                }
            }
            if (find < 0) break;

            int biggerpos = num.size()-1;
            for (; biggerpos > find; biggerpos--) {
                if (num[biggerpos] > num[find]) break;
            }
            
            swap(num[find], num[biggerpos]);
            sort(num.begin() + find +1, num.end());
            ans.push_back(num);
        }
        
        return ans;
    }
};

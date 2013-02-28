class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = 0;
        set<int> all;
        for (int i = 0; i < num.size(); i++) {
            all.insert(num[i]);
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (all.find(num[i]) != all.end()) {
                res = max(res, getcount(all, num[i]-1, false) + getcount(all, num[i], true));
            }
        }
        
        return res;
    }
    
    int getcount(set<int> &all, int t, bool up) {
        int total = 0;
        while (all.find(t) != all.end()) {
            total++;
            all.erase(t);
            t += up? 1: -1;
        }
        return total;
    }
};

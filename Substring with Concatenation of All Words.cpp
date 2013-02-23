class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res;

        map<string, int> index;
        map<string, int> cur;
        
        int n = L.size();
        if (n == 0) return res;
        int m = L[0].size();
        
        for(int i = 0; i < L.size(); ++i)  
            ++index[L[i]];
        
        for (int i = 0; i <= int(S.size()-m*n); i++) {
            cur.clear();
            int j = 0;
            for (; j < n; j++) {
                cur[S.substr(i+j*m, m)]++;
                if (cur[S.substr(i+j*m, m)] > index[S.substr(i+j*m, m)])
                    break;
            }
            if (j == n) res.push_back(i);
        }
        
        return res;
    }
};

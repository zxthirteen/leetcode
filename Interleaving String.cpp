class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool> > res(s1.size() +1, vector<bool>(s2.size() +1, false));
        res[0][0] = true;
        
        for (int i = 0; i < s1.size(); i++) {
            res[i+1][0] = res[i][0] && s1[i] == s3[i];
        }
        
        for (int i = 0; i < s2.size(); i++) {
            res[0][i+1] = res[0][i] && s2[i] == s3[i];
        }
        
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                if (s1[i] == s3[i+j+1]) res[i+1][j+1] = res[i+1][j+1] || res[i][j+1];
                if (s2[j] == s3[i+j+1]) res[i+1][j+1] = res[i+1][j+1] || res[i+1][j];
            }
        }
        
        return res[s1.size()][s2.size()];
    }
};

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > x(S.size()+1, vector<int>(T.size()+1, 0));
        x[0][0] = 1;
        for (int i = 1; i <= T.size(); i++) 
            x[0][i] = 0;
        for (int i = 1; i <= S.size(); i++)
            x[i][0] = 1;
        
        for (int i = 0; i < S.size(); i++) {
            for (int j = 0; j < T.size(); j++) {
                if (S[i] == T[j]) x[i+1][j+1] += x[i][j];
                x[i+1][j+1] += x[i][j+1]; 
            }
        }
        return x[S.size()][T.size()];
    }
};

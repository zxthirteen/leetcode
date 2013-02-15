class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> res;
        string line;
        int p = 0, q = -1;
        int sum = 0;
        
        while (p < words.size()) {
            q = p;
            sum = words[q].size();
            
            while (q+1 < words.size() && sum + q-p+1 + words[q+1].size() <= L) {
                q++;
                sum += words[q].size();
            } 
            
            if (p == q) {
                line = words[p];
                for (int i = 0; i < L - words[p].size(); i++)
                    line += ' ';
                p++;
            } else if (q == words.size() -1) {
                line = words[p];
                p++;
                for (; p <= q; p++) {
                    line += ' ';
                    line += words[p];
                }
                int spaces = L - line.size();
                for (int i = 0; i < spaces; i++) {
                    line += ' ';
                }
            } else {
                int space = (L - sum)/(q - p);
                int addition = L - sum - space * (q - p);
                
                line = words[p];
                p++;
                for (; p <= q; p++) {
                    for (int i = 0; i < space; i++)
                        line += ' ';
                    if (addition) {
                        line += ' ';
                        addition--;
                    }
                    line += words[p];
                }
            }
            res.push_back(line);
        }
        
        return res;
    }
};

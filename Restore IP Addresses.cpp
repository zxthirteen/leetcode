class Solution {
public:
    vector<string> res;
    int pos[4];
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        dfs(s, 0, 0);
        return res;
    }
    
    bool check(string &s, int start, int end) {
        string substr(s, start, end - start +1);
        int subint = atoi(substr.c_str());
        return 0 <= subint && subint <= 255;
    }
    
    void dfs(string &s, int dep, int start) {
        if (dep == 4) {
            if (start == s.size()) {
                string ip;
                int pos = 0;
                for (int i = 0; i < 4; i++) {
                    string part(s, pos, i - pos +1);
                    ip += i == 0 ? part : "." + part;
                }
                res.push_back(ip);
            }
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            if (check(s, start, i)) {
                pos[dep] = i;
                dfs(s, dep +1, i+1);
            }
        }
    }
};

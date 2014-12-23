/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
public:
    vector<string> res;
    int pos[4];
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        dfs(s, 0, 0);
        return res;
    }
    
    bool check(string &s, int start, int end) {
        string substr(s, start, end - start +1);
        switch (substr.size()) {
            case 1: return "0" <= substr && substr <= "9";
            case 2: return "10" <= substr && substr <= "99";
            case 3: return "100" <= substr && substr <= "255";
        }
        return false;
    }
    
    void dfs(string &s, int dep, int start) {
        if (dep == 4) {
            if (start == s.size()) {
                string ip;
                int k = 0;
                for (int i = 0; i < 4; i++) {
                    string part(s, k, pos[i] - k +1);
                    ip += i == 0 ? part : "." + part;
                    k = pos[i] +1;
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

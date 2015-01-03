/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        stringstream ss;
        int p = 0;
        while (true) {
            if (p >= strs[0].size()) {
                break;
            }
            char c = strs[0][p];
            int i = 1;
            for (; i < strs.size(); i++) {
                if (strs[i][p] != c) {
                    break;
                }
            }
            if (i != strs.size()) {
                break;
            }
            ss << c;
            p++;
        }
        return ss.str();
    }
};
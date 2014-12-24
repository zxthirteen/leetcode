/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        int n = S.size();
        int m = L.size();
        if (m == 0) return result;
        int wlen = L[0].size();
        unordered_map<string, int> needFind;
        unordered_map<string, int> hasFound;
        for (int i = 0; i < L.size(); i++) {
            needFind[L[i]]++;
        }
        
        for (int i = 0; i < n-m*wlen+1; i++) {
            hasFound.clear();
            int j = 0;
            for (; j < m; j++) {
                int p = i + j * wlen;
                string word = S.substr(p, wlen);
                if (needFind.find(word) == needFind.end()) {
                    break;
                }
                if (needFind[word] == hasFound[word]) {
                    break;
                }
                hasFound[word]++;
            }
            if (j == m) result.push_back(i);
        }
        
        return result;
    }
};
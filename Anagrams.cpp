/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        unordered_map<string, int> anamap;
        
        for(auto i = strs.begin(); i != strs.end(); i++) {
            string s = *i;
            sort(s.begin(), s.end());
            auto has = anamap.find(s);
            if (has == anamap.end()) {
                anamap.insert(make_pair(s, i-strs.begin()));
            } else {
                result.push_back(*i);
                if (has->second >= 0) {
                    result.push_back(strs[has->second]);
                    has->second = -1;
                }
            }
        }
    
        return result;
    }
};

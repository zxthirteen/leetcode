struct Pair {
    string s;
    int index;
    Pair(string ss, int ii): s(ss), index(ii) {}
};

bool comppair(Pair a, Pair b) {
    a.s < b.s;
}

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Pair> sortpair;
        vector<string> res;
        
        for (int i = 0; i < strs.size(); i++) {
            sortpair.push_back(Pair(strs[i], i));
            sort(sortpair[i].s.begin(), sortpair[i].s.end());
        }
        
        sort(sortpair.begin(), sortpair.end(), comppair);
        
        for (int i = 0; i < sortpair.size(); i++) {
            if ((i > 0 && sortpair[i].s == sortpair[i-1].s) 
                || (i < sortpair.size() -1 && sortpair[i].s == sortpair[i+1].s))
                res.push_back(strs[sortpair[i].index]);
        }
        
        return res;
    }
};

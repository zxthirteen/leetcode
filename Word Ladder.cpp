class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<string> q;
        unordered_set<string> used;
        
        q.push(start);
        q.push("");
        used.insert(start);
        int level = 1;
        
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            if (s != "") {
                string ns;
                for (int i = 0; i < s.size(); i++) {
                    ns = s;
                    for (int c = 'a'; c <= 'z'; c++) {
                        if (s[i] == c) continue;
                        ns[i] = c;
                        if (dict.find(ns) != dict.end() && used.find(ns) == used.end()) {
                            if (ns == end) return level+1;
                            q.push(ns);
                            used.insert(ns);
                        }
                    }
                }
            
            } else {
                if (q.empty()) break;
                else {
                    q.push("");
                    level++;
                }
            }
        }
        return 0;
    }
};

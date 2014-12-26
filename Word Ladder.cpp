/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/* 广度优先搜索 */

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
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

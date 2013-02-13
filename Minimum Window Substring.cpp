class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.empty() || T.empty()) return "";
        int minstart, minlen = INT_MAX;
        int len, count = 0, start = 0;;
        
        int target[256];
        int todo[256];
        
        memset(target, 0, sizeof(target));
        memset(todo, 0, sizeof(todo));
        
        for (int i = 0; i < T.size(); i++) {
            target[T[i]]++;
            todo[T[i]]++;
            count++;
        }
        
        for (int i = 0; i < S.size(); i++) {
            if (target[S[i]]) {
                todo[S[i]]--;
                if (todo[S[i]] >= 0)
                    count--;
            } else continue;
            
            if (count != 0) continue;
            while (count == 0) {
                if (target[S[start]]) {
                    todo[S[start]]++;
                    if (todo[S[start]] >= 1)
                        count++;
                }
                start++;
            }
            
            len = i - (start-1) + 1;
            if (len < minlen) {
                minstart = start -1;
                minlen = len;
            } 
        }
        
        if (minlen == INT_MAX) return "";
        else return string(S, minstart, minlen);
    }
};

class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return 0;
        int* ways = new int[s.size()];
        
        for (int i = 0; i < s.size(); i++) {
            ways[i] = 0;

            string sub = string(s, i, 1);
            int order;
            if ("1" <= sub && sub <= "9") {
                order = 1;
                if (i-1 >= 0)
                    order = order * ways[i-1];
                ways[i] += order;
            }
            if (i >= 1) {
                sub = string(s, i-1, 2);
                if ("10" <= sub && sub <= "26") {
                    order = 1;
                    if (i -2 >= 0)
                        order *= ways[i-2];
                    ways[i] += order;
                }
            }
        }
        
        return ways[s.size() -1];
    }
};

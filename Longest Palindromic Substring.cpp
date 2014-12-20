/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string ns = "#";
        int n = s.size();
        if (n <= 1) return s;
        for (int i = 0; i < n; i++) {
            ns.push_back(s[i]);
            ns.push_back('#');
        }
        
        vector<int> f(ns.size(), 0);
        int mid = 1;
        f[1] = 1;
        for (int i = 2; i < ns.size(); i++) {
            if (mid + f[mid] >= i) {
                int j = 2*mid -i;
                f[i] = min(mid + f[mid]-i, f[j]);
            } else f[i] = 0;
            
            while (i-f[i]-1 >= 0 && i+f[i]+1 <= ns.size()-1 
                    && ns[i+f[i]+1] == ns[i-f[i]-1]) f[i]++;
            if (f[i] > f[mid]) mid = i;
        }
        
        return s.substr((mid-f[mid])/2, f[mid]);
    }
};

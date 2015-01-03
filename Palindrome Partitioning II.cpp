/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

/*
我的方法，下面还有一个网上的好方法，可以免去存储palin[i][j]的cache
*/

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> palin(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);

        for (int len = 1; len <= n; len++) {
            for (int start = 0; start <= n-len; start++) {
                if (len == 1) {
                    palin[start][start] = true;
                    continue;
                }
                int end = start + len - 1;
                if (s[start] == s[end]) {
                    if (start+1 == end) {
                        palin[start][end] = true;
                    } else {
                        palin[start][end] = palin[start+1][end-1];
                    }
                } else {
                    palin[start][end] = false;
                }
            }
        }
        
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (palin[0][i] == true) {
                dp[i] = 1;
                continue;
            }
            for (int tail = i-1; tail >= 0; tail--) {
                if (palin[tail+1][i] == true) {
                    dp[i] = min(dp[i], dp[tail] + 1);
                }
            }
        }
        
        return dp.back()-1;
    }
};

/*
https://oj.leetcode.com/discuss/9476/solution-does-not-need-table-palindrome-right-uses-only-space
*/
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};
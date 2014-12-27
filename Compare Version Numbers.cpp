/*
Compare two version numbers version1 and version1.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/

/* 要注意1.1 == 1.0的情况 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size(), n = version2.size();
        int p = 0, q = 0;
        int res = 0;
        int v1 = 0, v2 = 0;
        while (p < m || q < n) {
            v1 = 0; v2 = 0;
            while (p < m && version1[p] != '.') {
                v1 = 10 * v1 + version1[p] - '0';
                p++;
            }
            
            while (q < n && version2[q] != '.') {
                v2 = 10 * v2 + version2[q] - '0';
                q++;
            }
            
            if (v1 < v2) {
                return -1;
            } else if (v1 > v2) {
                return 1;
            }
            
            if (p == m && q == n) {
                return 0;
            }
            
            p++;
            q++;
        }
        return res;
    }
};
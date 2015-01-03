/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/* 简单，但是要很仔细 */

class Solution {
public:
    string convert(string s, int nRows) {
        int n = s.size();
        if (n <= 1 || nRows <= 1) return s;
        stringstream res;
        int part = 2*nRows - 2;
        for (int row = 0; row < nRows; row++) {
            int j = 0;
            if (row == 0) {
                j = 0;
                while (j < n) {
                    res << s[j];
                    j += part;
                }
            } else if (row == nRows-1) {
                j = nRows - 1;
                while (j < n) {
                    res << s[j];
                    j += part;
                }
            } else {
                j = row;
                while (j < n) {
                    res << s[j];
                    j += 2* (nRows -1-row);
                    if (j < n) {
                        res << s[j];
                        j += 2 * row;
                    }
                }
            }
        }
        return res.str();
    }
};
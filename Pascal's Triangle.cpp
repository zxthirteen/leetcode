/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0) {
            return result;
        }
        
        vector<int> row(1, 1);
        result.push_back(row);
        for (int i = 2; i <= numRows; i++) {
            row.push_back(0);
            for (int j = i-1; j > 0; j--) {
                row[j] += row[j-1];
            }
            result.push_back(row);
        }
        
        return result;
    }
};
/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size();
        if (m == 0) return 1;
        int n = dungeon[0].size();
        
        if (n == 0) return 1;
        
        vector<int> line(n, INT_MAX);
        line[n-1] = 1;
        
        for (int i = m-1; i >= 0; i--) {
            line[n-1] -= dungeon[i][n-1];
            if (line[n-1] < 1) {
                line[n-1] = 1;
            }
            for (int j = n-2; j >= 0; j--) {
                line[j] = min(line[j+1], line[j]) - dungeon[i][j];
                if (line[j] < 1) {
                    line[j] = 1;
                }
            }
        }
        return line[0];
    }
};
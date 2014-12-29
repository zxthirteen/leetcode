/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

/* 
很激动。。。自己想出来的方法，
首先合并成一组整数，从某一个位置（比如0）开始求和，一旦出现负数，说明：起始位置不可能是之前的任何一个结点
就把当前位置加1作为新的起始位置
O(n)
*/

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = cost.size();
        vector<int> steps(n, 0);
        for (int i = 0; i < n; i++) {
            steps[i] = gas[i] - cost[i];
        }
        if (n == 1) {
            return gas[0] >= cost[0] ? 0: -1;
        }
        
        int start = 0;
        while (start < n) {
            int sum = 0;
            int p = 0;
            while (p < n) {
                sum += steps[(start + p) %n];
                if (sum < 0) {
                    start += p +1;
                    break;
                }
                p++;
            }
            if (p == n) {
                return start;
            }
        }
        return -1;
    }
};
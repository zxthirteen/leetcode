/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

struct Node {
    int val;
    int index;
    Node(int v, int i): val(v), index(i){}
};

bool comp(Node a, Node b) {
    return a.val < b.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<Node> all;
        int n = numbers.size();
        for (int i = 0; i < n; i++) all.push_back(Node(numbers[i], i+1));
        
        sort (all.begin(), all.end(), comp);
        vector<Node>::iterator i = all.begin(), j = all.end()-1;
        
        vector<int> res;
        
        while (i < j) {
            if ((*i).val + (*j).val == target) {
                res.push_back((*i).index);
                res.push_back((*j).index);
                if (res[0] > res[1]) swap(res[0], res[1]);
                return res;
            } else if ((*i).val + (*j).val < target)
                i++;
            else 
                j--;
        }
        
        return res;
    }
};

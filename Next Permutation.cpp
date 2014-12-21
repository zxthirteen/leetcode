/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size();
        int p = n-2;
        while (p >= 0) {
            if (num[p] < num[p+1])
                break;
            p--;
        }
        if (p < 0) {
            sort(num.begin(), num.end());
            return;
        }
        
        int tmp = n-1;
        while (num[tmp] <= num[p]) tmp--;
        swap(num[p], num[tmp]);
        sort(num.begin()+p+1, num.end());
    }
};

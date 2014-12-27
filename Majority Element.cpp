/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int maj = 0;
        int count = 0;
        int n = num.size();
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                maj = num[i];
                count++;
            } else {
                if (maj == num[i]) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return maj;
    }
};
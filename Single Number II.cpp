/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

/* 两个都是O(n)时间的算法，一个稍简单理解但是代码效率稍低，后一个是很好是改进算法，见：
中文网页：
http://www.tuicool.com/articles/fAZZv2a
英文网页：
https://oj.leetcode.com/discuss/9763/accepted-proper-explaination-does-anyone-have-better-idea
以下代码摘自其中的中文网页
*/

int singleNumber(int A[], int n) {
  int count[32] = {0};
  int result = 0;
  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < n; j++) {
      if ((A[j] >> i) & 1) {
        count[i]++;
      }
    }
    result |= ((count[i] % 3) << i);
  }
  return result;
}

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];
            ones ^= A[i];// 异或3次 和 异或 1次的结果是一样的
             //对于ones 和 twos 把出现了3次的位置设置为0 （取反之后1的位置为0）
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};
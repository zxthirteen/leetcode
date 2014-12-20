/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/

// below is the best solution online
// !!! The similar problem is discussed in Column 8 in 'Programming Pearls" book, which is consider sum, not product

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) {
            return 0;
        }
    
        int maxherepre = A[0];
        int minherepre = A[0];
        int maxsofar = A[0];
        int maxhere, minhere;
    
        for (int i = 1; i < n; i++) {
            maxhere = max(max(maxherepre * A[i], minherepre * A[i]), A[i]);
            minhere = min(min(maxherepre * A[i], minherepre * A[i]), A[i]);
            maxsofar = max(maxhere, maxsofar);
            maxherepre = maxhere;
            minherepre = minhere;
        }
        return maxsofar;
    }
};

/*
my original solution
*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int scanArray(int A[], int n, int start, int end, int& first, int& last) {
        first = start -1;
        last = start -1;
        int count = 0;

        int p = start;
        while (p <= end) {
            if (A[p] < 0) {
                if (first == start -1) {
                    first = p;
                }
                last = p;
                count++;
            }
            p++;
        }
        return count;
    }

    int maxProduct(int A[], int n) {
        if (n == 1) return A[0];
        // if the array have more than one element, the result can't be smaller than 0
        int r = 0;
        int start = 0;
        int end;

        while (start < n) {
            while (start < n && A[start] == 0) {
                start ++;
            }
            if (start == n) break;
            end = start;
            while (end + 1 < n && A[end+1] != 0) end ++;
            int part = calPart(A, n, start, end);
            if (part > r) r = part;
            start = end + 1;
        }
        return r;
    }

    int calPart(int A[], int n, int start, int end) {
        if (start == end) return A[start];
        // find the first and last negative num
        int first;
        int last;
        int count = scanArray(A, n, start, end, first, last);

        if (count % 2 == 0) return maltipul(A, start, end);

        // find out should we abandon the first or the last negative num
        int head = maltipul(A, start, first);
        int tail = maltipul(A, last, end);

        if (head < tail) {
            return maltipul(A, start, last-1);
        } else {
            return maltipul(A, first+1, end);
        }
    }

    int maltipul(int A[], int i, int j) {
        int r = 1;
        for (int p = i; p <= j; p++) {
            r *= A[p];
        }
        return r;
    }
};

int main() {
    cout << "Hello, World!" << endl;

    Solution s;

    int A[] = {-2, 0,-1};
    int n = 3;
    cout << s.maxProduct(A, n) << endl;
    cout << s.calPart(A, n, 0, 0) << endl;

    return 0;
}

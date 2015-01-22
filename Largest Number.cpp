/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

/* 
注意：如果比较 12和12xxx,结果是不一定的
详见compstr，相当于把a+b和b+a两个字符串做了比较，通过到结尾就换指针位置的方法
*/

bool compstr(string a, string b) {
    auto i = a.begin();
    auto j = b.begin();
    int m = a.size(), n = b.size();
    for (int p = 1; p <= m+n; p++) {
        if (i == a.end()) i = b.begin();
        if (j == b.end()) j = a.begin();
        if (*i != *j) return *i > *j;
        else {
            i++;
            j++;
        }
    }
    return false;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        int n = num.size();
        vector<string> numstr(n, "");
        for (int i = 0; i < n; i++) {
            stringstream ss;
            ss << num[i];
            numstr[i] = ss.str();
        }
        sort(numstr.begin(), numstr.end(), compstr);
        
        stringstream resstream;
        for (int i = 0; i < n; i++) {
            resstream << numstr[i];
        }
        string res = resstream.str();
        int i = 0;
        while (i != res.size() && res[i] == '0') {
            i++;
        }
        return i == res.size() ? "0" : res.substr(i);
    }
};
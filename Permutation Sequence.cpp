class Solution {
public:
    string res;
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res = "";
        for (int i = 1; i <= n; i++)
            res.push_back('0' + i);
            
        getk(0, k);    
        return res;
    }
    
    void getk(int start, int k) {
        if (start == res.size()) return;
        int unit = 1;
        for (int i = 2; i < res.size()-start; i++) unit *= i;
        sort(res.begin() + start, res.end());
        int unitnum = 0;
        while ((unitnum+1)*unit < k) unitnum++;
        
        swap(res[start], res[start+unitnum]);
        getk(start +1, k - (unitnum)*unit);
    }
};

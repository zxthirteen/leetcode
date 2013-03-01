class Solution {
public:
    vector<string> res;
    string oneres;
    vector<string> board;
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        oneres = string(digits.size(), '0');
        if (digits.empty()) {
            res.push_back("");
            return res;
        }
        init();
        dfs(digits, 0);
        return res;
    }
    
    void dfs(string d, int deep) {
        if (deep == d.size()) {
            res.push_back(oneres);
            return;
        }
        
        int index = d[deep]-'0';
        for (int i = 0; i < board[index].size(); i++) {
            oneres[deep] = board[index][i];
            dfs(d, deep+1);
        }
        
    }
    
    void init() {
        board.clear();
        board.push_back("");
        board.push_back("");
        board.push_back("abc");
        board.push_back("def");
        board.push_back("ghi");
        board.push_back("jkl");
        board.push_back("mno");
        board.push_back("pqrs");
        board.push_back("tuv");
        board.push_back("wxyz");
    }
};

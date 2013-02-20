class Solution {
vector<int> pos;
int m;
vector<vector<string> > res;

class Node {
public:
    int x;
    int y;
    Node(int xx, int yy): x(xx), y(yy) {}
};

public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        pos = vector<int>(n, 0);
        if (n == 0) return res;
        
        m = n;
        stack<Node> s;
        for (int i = 0; i < m; i++)
            s.push(Node(0, i));
            
        while (!s.empty()) {
            Node node = s.top();
            s.pop();
            if (check(node.x, node.y)) {
                pos[node.x] = node.y;       
                if (node.x == m-1) {
                    addres();
                } else {
                    for (int k = 0; k < m; k++)
                        s.push(Node(node.x+1, k));
                }
            } else {
                // do nothing;
            }
            
        }
        
        return res;
    }
    
    bool check(int i, int j) {
        for (int k = 0; k < i; k++) {
            if (pos[k] == j) return false;
        }
        
        int x = i, y = j;
        while (0 <= --x && 0 <= --y) {
            if (pos[x] == y) return false;
        }
        
        x = i;
        y = j;
        while (0 <= --x && ++y < m) {
            if (pos[x] == y) return false;
        }
        
        return true;
    }
    
    void addres() {
        vector<string> oneres(m, string(m, '.'));
        for (int i = 0; i < m; i++)
            oneres[i][pos[i]] = 'Q';
        res.push_back(oneres);
    }
};

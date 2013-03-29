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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
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

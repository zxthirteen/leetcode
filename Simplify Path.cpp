class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (path.empty()) return "";
        string str("");
        deque<string> parts;
        
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (str != "") {
                    if (str == ".." ) {
                        if (!parts.empty()) parts.pop_back();
                    } else if (str != ".") {
                        parts.push_back(str);
                    }
                    str.clear();
                }
            } else {
                str.push_back(path[i]);
            }
        }
        
        string res;
        if (parts.empty()) return "/";
        while (!parts.empty()) {
            res += '/';
            res += parts.front();
            parts.pop_front();
        }
        
        return res;
    }
};

/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
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

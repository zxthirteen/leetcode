class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int res = -0;
        bool posi = true;
        
        while (*str == ' ') str++;
        
        if (*str == '-') {
            posi = false;
            str++;
        } else if (*str == '+') {
            str++;
        }
        
        while (*str >= '0' && *str <= '9') {
            if (res < (INT_MIN + *str-'0')/10) {
                res = INT_MIN;
                break;
            }
            res *= 10;
            res -= *str-'0';
            str++;
        }
        
        if (posi && res == INT_MIN) res++;
        return posi? -res: res;
    }
};

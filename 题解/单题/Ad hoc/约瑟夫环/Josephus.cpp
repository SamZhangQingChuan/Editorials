class Solution {
public:
    int lastRemaining(int n, int m) {
        /*
        设 ind 表示上一层的结果，len 表示当前人数
        则 f(len) = (m + f(len-1)) mod len
        */
        int ind = 0;
        for(int len = 2; len <= n; len++) {
            ind = (m + ind) % len;
        }
        return ind;
    }
};

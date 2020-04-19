int KMP(string S, string T) {
    string s = " " + S + "#" + T; // 在前面添加空格使得下标从 1 开始
    vector<int> next(s.size());
    next[1] = 0;
    for(int i = 2; i < s.size(); i++) {
        for(int len = next[i - 1];; len = next[len]) {
            if(s[len + 1] == s[i]) {  // 如果找到了可以转移的 border
                next[i] = len + 1;
                break;
            } else {
                if(len == 0) { // 如果没有可以转移的
                    next[i] = 0;
                    break;
                }
            }
        }
    }
    // 枚举 T 的部分有多少位置 next[i] = |S|
    int count = 0;
    for(int i = 1; i <= T.size(); i++) {
        count += next[i + S.size() + 1] == S.size();
    }
    return count;
}

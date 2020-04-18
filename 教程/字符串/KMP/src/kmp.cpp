int KMP(string S, string T) {
    string s = " " + S + "#" + T;
    vector<int> next(s.size());
    for(int i = 1; i < s.size(); i++) {
        for(int len = next[i];; len = next[len]) {
            if(s[len + 1] == s[i + 1]) {
                next[i + 1] = len + 1;
                break;
            } else {
                if(len == 0) {
                    break;
                }
            }
        }
    }
    int count = 0;
    for(int i = 0; i < T.size(); i++) {
        count += next[i + S.size() + 1] == S.size();
    }
    return count;
}

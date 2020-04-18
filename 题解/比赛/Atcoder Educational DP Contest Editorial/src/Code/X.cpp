struct Brick {
    int w, s, v;
    bool operator<(const Brick &other) const {
        return w + s > other.w + other.s;
    }
};
int main() {
    int n;cin >> n; 
    vector<Brick> bricks(n);
    for(auto &brick:bricks) cin >> brick.w >> brick.s >> brick.v;
    sort(begin(bricks), end(bricks));
    const long long maxs = 10010;
    // 无穷大设为两倍最大承重即可
    vector<long long> dp(2 * maxs + 10, 0);
    // 类似于完全背包的写法，因为最大承重只会降低，所以从小的开始枚举
    for(auto brick:bricks) 
        for(int j = brick.w; j < dp.size(); j++) 
            if(dp[min(j - brick.w, brick.s)] < dp[j] + brick.v) 
                dp[min(j - brick.w, brick.s)] = dp[j] + brick.v;
    cout << *max_element(begin(dp), end(dp)) << endl;
}

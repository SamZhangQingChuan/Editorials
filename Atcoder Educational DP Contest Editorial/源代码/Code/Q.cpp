set<pair<long, long>> s;
// 存一个初始决策防止无可用决策
s.insert({0, 0});
for(int i = 1; i <= n; i++) {
    //找出前面高度最接近的
    auto optimal = prev(s.lower_bound({h[i], 0}));
    dp[i] = optimal->second + a[i];
    while(true) {
        auto next = s.lower_bound({h[i], 0});
        // 如果存在之后的决策更劣就剔除出去
        if(next != s.end() and next->second <= dp[i])
            s.erase(next);
        else
            break;
    }
    s.insert({h[i], dp[i]});
}

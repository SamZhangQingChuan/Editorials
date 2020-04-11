/*
    sum 维护 区间sum
    dp  维护 区间max
    update - 区间add
    query  - 区间max
*/
for(int i = 1; i <= m; i++) {
    int l, r, a;
    cin >> l >> r >> a;
    sum.update(l, r, 1, a);
    /*
        在 l   加入线段
        在 r+1 移走线段
    */
    start[l].push_back({{l, r}, a});
    finish[r + 1].push_back({{l, r}, a});
}
long long ans = 0;
for(int i = 1; i <= n; i++) {
    // 加入
    for(auto interval:start[i]) {
        int l, r, a = interval.second;
        tie(l, r) = interval.first;
        dp.update(l, r, 1, -a);
    }
    // 移走
    for(auto interval:finish[i]) {
        int l, r, a = interval.second;
        tie(l, r) = interval.first;
        dp.update(l, r, 1, a);
    }
    // 求 sum[i]
    long long s = LLONG_MIN;
    sum.query(i, i, 1, s);
    // 求dp[0..i-1]的最优值
    long long max = LLONG_MIN;
    dp.query(0, i - 1, 1, max);
    // 更新 dp[i]
    dp.update(i, i, 1, max + s);
    if(max + s > ans)
        ans = max + s;
}

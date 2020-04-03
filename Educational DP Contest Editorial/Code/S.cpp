dp[0][0][0] = 1;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < d; j++) {
        for(int k = 0; k < 2; k++) {
            for(int cur = 0; cur < 10; cur++) {
                // 如果之前没有已经小于，那么当前位不能超过上界
                if(!k and cur > r[i])break;
                dp[i + 1][(j + cur) % d][k or cur < r[i]] += dp[i][j][k];
            }
        }
    }
}
// 小于上界 + 不小于上界（即等于上界） - 0的情况（因为题目里不包含0）
ans = dp[n][0][0] + dp[n][0][1] - 1;

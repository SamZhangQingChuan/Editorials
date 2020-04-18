dp[0] = 1;
for(int mask = 1; mask < (1 << n); mask++) {
    int i = __builtin_popcount(mask) - 1;
    for(int j = 0; j < n; j++) {
        //1. i 和 j 相连
        //2. j 包含在 mask 中
        if(connected[i][j] and (mask & (1 << j)) != 0) {
            dp[mask] += dp[mask - (1 << j)];
        }
    }
}

dp[0][0] = 1;
for(int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    for(int j = 0; j < k; j++) {
        dp[i][j + 1] = dp[i][j] + dp[i - 1][j + 1];
        if(j - a[i] >= 0)
            dp[i][j + 1] -= dp[i - 1][j - a[i]];
    }
}

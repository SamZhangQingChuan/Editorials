dp[1][1] = 1;
for(int i = 1; i <= h; i++) {
    for(int j = 1; j <= w; j++) {
        if(i == 1 and j == 1)continue;
        if(dp[i][j] == '.') //如果可以经过
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
}

prob[0][0] = 1;
for(int i = 1;i<=n;i++){
    dp[i][0] = dp[i-1][0] * (1-p[i]);
    for(int j = 1;j<=i;j++){
        dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1-p[i]);
    }
}

ans = 0;
for(int j = 0;j<=n;j++){
    if(j > n-j){
        ans += dp[n][j];
    }
}
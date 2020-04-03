dp[1][1] = 1;
for(int l = 2; l <= n; l++) {
    if(s[l - 1] == '<') {
        for(int x = 1; x <= l; x++) {
            dp[l][x] = dp[l][x - 1] + dp[l - 1][x - 1];
        }
    } else if(s[l - 1] == '>') {
        for(int x = l; x >= 1; x--) {
            dp[l][x] = dp[l][x + 1] + dp[l - 1][x];
        }
    }
}
long long ans = 0;
for(int i = 1; i <= n; i++)
    ans += dp[n][i];

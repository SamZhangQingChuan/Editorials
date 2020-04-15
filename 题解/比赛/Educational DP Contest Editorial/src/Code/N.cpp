long long solve(int l, int r) {
    if(l == r) {
        return 0;
    } else {
        if(dp[l][r] != inf) {//已经计算
            return dp[l][r];
        } else {
            for(int m = l; m < r; m++) {
                dp[l][r] = min(dp[l][r], solve(l, m) + solve(m + 1, r));
            }
            for(int i = l; i <= r; i++) {
                dp[l][r] += a[i];
            }
            return dp[l][r];
        }
    }
}

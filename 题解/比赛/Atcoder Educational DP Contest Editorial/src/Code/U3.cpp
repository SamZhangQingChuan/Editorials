for(int mask = 0; mask < (1 << n); mask++) {
    for(int submask = mask; submask > 0; submask = (submask - 1) & mask) {
        dp[mask] = max(dp[mask], dp[mask - submask] + cost[submask]);
    }
}

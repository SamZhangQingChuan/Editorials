void calc(int i) {
    if(vis[i])
        return dp[i];
    else {
        dp[i] = 0;
        vis[i] = true;
        for(auto j:reversed_edges[i]) {
            dp[i] = max(dp[i], calc(j) + 1);
        }
        return dp[i];
    }
}

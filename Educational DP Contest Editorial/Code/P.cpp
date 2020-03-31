void dfs(int cur, int fa = 0) {
    dp[cur][0] = dp[cur][1] = 1;
    for(auto son:edge[cur]) {
        if(son != fa) {
            dfs(son, cur);
            dp[cur][0] *= dp[son][1];
            dp[cur][1] *= dp[son][0] + dp[son][1];
        }
    }
}
dfs(1);
ans = dp[1][0] + dp[1][1];
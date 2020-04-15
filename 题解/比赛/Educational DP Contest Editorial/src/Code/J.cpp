double calc(int b, int c, int d) {
    if(min({b,c,d}) < 0)return 0;
    if(vis[b][c][d])
        return dp[b][c][d];
    else {
        vis[b][c][d] = true;
        double sum = b + c + d;
        dp[b][c][d] = n / sum
                    + b / sum * calc(b - 1, c, d)
                    + c / sum * calc(b + 1, c - 1, d)
                    + d / sum * calc(b, c + 1, d - 1);
        return dp[b][c][d];
    }
}

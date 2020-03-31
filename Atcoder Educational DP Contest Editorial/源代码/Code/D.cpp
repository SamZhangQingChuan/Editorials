//注意要开 long long
for(int i = 1;i<=n;i++)
    for(int j = 0;j<=W;j++)
        if(j < w[i])
        //容量不够
            dp[i][j] = dp[i-1][j];
        else
        //容量足够
            dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
int bound = n*1000;//最大价值
for(int v = 0;v<=bound;v++)
    if(v == 0) dp[0][v] = 0;
    else dp[0][v] = inf;
for(int i = 1;i<=n;i++)
    for(int tot = 0;tot<=bound;tot++)
        if(tot < v[i])
            dp[i][tot] = dp[i-1][tot]
        else
            dp[i][tot] = min(dp[i-1][tot],dp[i-1][tot-v[i]] + w[i]);
answer = 0
for(int tot = 0;tot<=bound;tot++)
    if(dp[n][tot] <= W)
        answer = tot


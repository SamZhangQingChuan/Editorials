// 计算最优长度
for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        if(s[i] == t[j])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
// 恢复答案
int i = n, j = m;
while(dp[i][j] > 0)
    if(s[i] == t[j]) {
        ans[dp[i][j]] = s[i];
        i--;
        j--;
    } else {
        if(dp[i][j] == dp[i - 1][j])i--;
        else j--;
    }

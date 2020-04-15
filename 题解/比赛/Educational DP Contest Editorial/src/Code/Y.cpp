dp[0][1] = 1;
for(int i=1;i<n+2;i++) {
    for(int j = 0;j<i;j++){
        if(x[j]<=x[i] and y[j]<=y[i]){
            for(int parity = 0;parity<2;parity++){
                dp[i][0] += dp[j][1] * binomial(x[i]-x[j]+y[i]-y[j],x[i]-x[j])
            }
        }
    }
}
ans = dp[n-1][0] - dp[n-1][1]
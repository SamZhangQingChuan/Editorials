void solve(int l,int r){
    if(dp[l][r] != -1)return;
    else{
        if(l == r){
            dp[l][r] = a[l];
        }else{
            solve(l+1, r);
            solve(l, r-1);
            dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
}

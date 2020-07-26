dp[0] = false;//终局必败
for(int i = 1;i<=k;i++){
    //默认必败
    dp[i] = false;
    for(int j = 0;j<n;j++){
        //如果存在方法使得对手必败，那么当前必胜
        if(i >= a[j] and dp[i-a[j]] == false){
            dp[i] = true;
        }
    }
}
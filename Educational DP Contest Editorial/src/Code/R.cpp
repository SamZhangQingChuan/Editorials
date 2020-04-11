const int maxn = 50;
typedef array<array<int, maxn>, maxn> State;
long long n, k;

State mul(State a, State b) {
    State res;
    // 初始化
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)res[i][j] = 0;
    
    // i,k,j的顺序通过缓存优化加快寻址速度
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < n; j++) {
                res[i][j] += 1ll * a[i][k] * b[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }
    
    return res;
}

State power(State base, long long k) {
    if(k == 1)return base;
    else if(k % 2 == 0) {
        auto half = power(base, k / 2);
        return mul(half, half);
    } else {
        return mul(power(base, k - 1), base);
    }
}

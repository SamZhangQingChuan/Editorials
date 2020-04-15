long long ans[maxn], dp[maxn];

// 第一次 dfs 只计算向下的方案数
void dfs1(ll cur, ll fa) {
    dp[cur] = 1;
    for(auto s:son[cur]) {
        if(s != fa) {
            dfs1(s, cur);
            (dp[cur] *= dp[s] + 1) %= mod;
        }
    }
}

// 第二次 dfs 计算每个点的答案，其中 faContribution 表示来自父亲的贡献
// 由于根节点没有父亲，向上仅有一种方案，于是默认值为 1
void dfs2(ll cur, ll fa, ll faContribution = 1) {
    ans[cur] = dp[cur] * faContribution % mod;
    vector<long long> prefix_prod, suffix_prod;
    for(auto s:son[cur]) {
        if(s != fa) {
            prefix_prod.push_back(dp[s] + 1);
        }
    }
    
    suffix_prod = prefix_prod;
    for(int i = 1; i < prefix_prod.size(); i++)
        (prefix_prod[i] *= prefix_prod[i - 1]) %= mod;
    for(int i = (int) suffix_prod.size() - 2; i >= 0; i--)
        (suffix_prod[i] *= suffix_prod[i + 1]) %= mod;
    
    int cnt = 0;
    for(auto s:son[cur]) {
        if(s != fa) {
            long long contribution = faContribution;
            if(cnt > 0) 
                (contribution *= prefix_prod[cnt - 1]) %= mod;
            if(cnt + 1 < suffix_prod.size()) 
                (contribution *= suffix_prod[cnt + 1]) %= mod;
            dfs2(s, cur, contribution + 1);
            cnt++;
        }
    }
}

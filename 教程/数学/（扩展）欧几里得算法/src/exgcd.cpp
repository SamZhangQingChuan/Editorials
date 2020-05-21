using ll = long long;

tuple<ll, ll, ll> exGCD (ll a, ll b) {
    // 1. 初始化
    tuple<ll, ll, ll> equation[2] = {{1, 0, a},
                                     {0, 1, b}};
    int cnt = 0;
    while (get<2> (equation[1]) != 0) {
        // 2. 获取商
        ll q = get<2> (equation[0]) / get<2> (equation[1]);
        // 3. 得到新的等式
        equation[0] = {
                get<0> (equation[0]) - q * get<0> (equation[1]),
                get<1> (equation[0]) - q * get<1> (equation[1]),
                get<2> (equation[0]) - q * get<2> (equation[1])
        };
        swap (equation[0], equation[1]);
    }
    return equation[0];
}

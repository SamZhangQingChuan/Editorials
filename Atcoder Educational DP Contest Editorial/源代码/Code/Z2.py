dp = [0,inf,inf,...] # 下标从0开始
optimal_strategy = [(1,2)] # 一开始0是所有状态的最优策略
for j in [2..n]:
# 首先二分出当前位置的最优策略
    l = 1, r = optimal_strategy.length()
    while l < r:
        mid = (l + r) / 2 + 1
        if optimal_strategy[mid][0] <= j:
            l = mid
        else:
            r = mid-1
    dp[j] = cost(optimal_strategy[l][0],j)
# 然后我们计算成为最优决策的起点
    # 首先去除完全劣于当前策略的策略
    i,pos = optimal_strategy.back()
    while cost(i,pos) > cost(j,pos):
        optimal_strategy.pop()
        i,pos = optimal_strategy.back()
    # 开始二分起点
    l = pos, r = n
    while l < r:
        mid = (l + r) / 2
        if cost(i,mid) <= cost(j,mid):
            l = mid + 1
        else:
            r = mid
    optimal_strategy.push((j,l)); # 二分后l就是想求的起点
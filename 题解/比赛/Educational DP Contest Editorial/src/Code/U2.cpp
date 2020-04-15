for(int mask = 0; mask < (1 << n); mask++) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(((1 << i) & mask) and ((1 << j) & mask)) {
                cost[mask] += a[i][j];

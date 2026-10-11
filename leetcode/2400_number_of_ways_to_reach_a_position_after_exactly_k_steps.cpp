// 2400.恰好移动到 k 步到达某一位置的方法数目
//
// 给你两个 正 整数 startPos 和 endPos 。最初，你站在 无限 数轴上位置 startPos 处。在一步移动中，你可以向左或者向右移动一个位置。
// 给你一个正整数 k ，返回从 startPos 出发、恰好 移动 k 步并到达 endPos 的 不同 方法数目。由于答案可能会很大，返回对 109 + 7 取余 的结果。
// 如果所执行移动的顺序不完全相同，则认为两种方法不同。
// 注意：数轴包含负整数。

int numberOfWays(int startPos, int endPos, int k) {
    int gap = abs(endPos - startPos);
    if (gap > k || (k - gap) % 2 != 0) return 0;
    int a = (k + gap) / 2;
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp(k + 1, vector<long long>(k + 1, 0));
    for (int i = 0; i <= k; ++i) {
        dp[i][0] = dp[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
        }
    }
    return dp[k][a];
}


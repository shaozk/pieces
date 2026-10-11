// 2320.统计放置房子的方式数
//
// 一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。
// 现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。由于答案可能很大，需要对 109 + 7 取余后再返回。
// 注意，如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i 个地块放置房子。

const int MOD = 1e9 + 7;
int countHousePlacements(int n) {
    long long pre = 1, cur = 2;
    for (int i = 2; i <= n; ++i) {
        long long tmp = (pre + cur) % MOD;
        pre = cur;
        cur = tmp;
    }
    return 1LL * (cur * cur) % MOD;
}


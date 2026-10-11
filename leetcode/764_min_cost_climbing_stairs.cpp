// 764.使用最小花费爬楼梯
//
// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
// 一旦你支付此费用，即可选择向上爬 一个 或者 两个 台阶。
// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
// 请你计算并返回达到楼梯顶部的 最低 花费，即最后一步之后的那个位置（下标 cost.length）。


int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int pre = 0, cur = 0;
    for (int i = 2; i <= n; ++i) {
        int next = min(cur + cost[i - 1], pre + cost[i - 2]);
        pre = cur;
        cur = next;
    }
    return cur;
}


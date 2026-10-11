// 2244.完成所有任务需要的最少轮数
//
// 给你一个下标从 0 开始的整数数组 tasks ，其中 tasks[i] 表示任务的难度级别。在每一轮中，你可以完成 2 个或者 3 个 相同难度级别 的任务。
// 返回完成所有任务需要的 最少 轮数，如果无法完成所有任务，返回 -1 。

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> map;
    for (int t : tasks) {
        map[t]++;
    }
    int ret = 0;
    for (auto [_, v] : map) {
        if (v == 1) {
            return -1;
        } else if (v % 3 == 0) {
            ret += v / 3;
        } else {
            ret += v / 3 + 1;
        }
    }
    return ret;
}


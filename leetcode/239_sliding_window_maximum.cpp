// 239.滑动窗口最大值
//
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<pair<int, int>> que;
    for (int i = 0; i < k; ++i) {
        que.emplace(nums[i], i);
    }
    vector<int> ret{que.top().first};
    for (int i = k; i < n; ++i) {
        que.emplace(nums[i], i);
        while (que.top().second <= i - k) {
            que.pop();
        }
        ret.push_back(que.top().first);
    }
    return ret;
}


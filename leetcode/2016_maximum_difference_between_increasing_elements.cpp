// 2016.增量元素之间的最大差值
//
// 给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。
// 返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。

int maximumDifference(vector<int>& nums) {
    int ret = -1, n = nums.size();
    int premin = nums[0];
    for (int i = 0; i < n; ++i) {
        if (nums[i] <= premin) {
            premin = nums[i];
        } else {
            ret = max(ret, nums[i] - premin);
        }
    }
    return ret;
}


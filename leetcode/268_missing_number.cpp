// 268.丢失的数字
//
// 给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

int missingNumber(vector<int>& nums) {
    int ret = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        ret ^= nums[i];
    }
    for (int i = 0; i <= n; ++i) {
        ret ^= i;
    }
    return ret;
}


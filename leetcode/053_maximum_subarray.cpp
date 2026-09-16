// 53.最大子数组和
//
// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// 子数组是数组中的一个连续部分。


int maxSubArray(vector<int>& nums) {
    int result = nums[0], pre = 0;
    for (const auto& x : nums) {
        pre = max(x, pre + x);
        result = max(result, pre);
    }
    return result;


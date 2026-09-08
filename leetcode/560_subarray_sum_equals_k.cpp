// 560.和为 K 的子数组
//
// 给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
// 子数组是数组中元素的连续非空序列。

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    int n = nums.size(), result = 0, pre = 0;
    mp[0] = 1;
    for (auto& item : nums) {
        pre += item;
        if (mp.find(pre - k) != mp.end()) {
            result += mp[pre - k];
        } 
        mp[pre]++;
    }
    return result;
}


// 15.三数之和
// 
// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int target = -nums[i];
        int k = n - 1;
        for (int j = i + 1; j < n; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            while (j < k && nums[j] + nums[k] > target) {
                --k;
            }
            if (j == k) {
                break;
            }
            if (nums[j] + nums[k] == target) {
                ans.push_back({nums[i], nums[j], nums[k]});
            }
            
        }
        
    }
    return ans;
}

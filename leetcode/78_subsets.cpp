// 78.子集
//
// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

void backtrack(vector<vector<int>>& vec, vector<int>& path, vector<int>& nums, int cur) {
    vec.push_back(path);
    for (int i = cur; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        backtrack(vec, path, nums, i + 1);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> path;
    backtrack(ret, path, nums, 0);
    return ret;
}


// 46.全排列
//
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

void backtrack(vector<vector<int>>& vec, vector<int>& path, int ind, int end) {
    if (ind == end) {
        vec.push_back(path);
        return;
    }
    for (int i = ind; i < end; ++i) {
        swap(path[i], path[ind]);
        backtrack(vec, path, ind + 1, end);
        swap(path[i], path[ind]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    backtrack(ret, nums, 0, nums.size());
    return ret;
}


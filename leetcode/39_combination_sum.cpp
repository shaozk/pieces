// 39.组合总数
//
// 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。


void backtrack(vector<vector<int>>& vec, vector<int>& path, vector<int>& candidates, int ind, int target) {
    if (target == 0) {
        vec.push_back(path);
        return;
    }
    for (int i = ind; i < candidates.size(); ++i) {
        if (candidates[i] > target) break;
        path.push_back(candidates[i]);
        backtrack(vec, path, candidates, i, target - candidates[i]);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> path;
    sort(candidates.begin(), candidates.end());
    backtrack(ret, path, candidates, 0, target);
    return ret;
}

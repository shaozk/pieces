// 40.组合总和II
//
// 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用 一次 。
// 注意：解集不能包含重复的组合。 


void backtrack(vector<vector<int>>& vec, vector<int>& path, vector<int>& cands, int ind, int target) {
    if (target == 0) {
        vec.push_back(path);
        return;
    }
    unordered_set<int> used;
    for (int i = ind; i < cands.size(); ++i) {
        if (cands[i] > target) break;
        if (i > ind && cands[i] == cands[i - 1]) continue;
        if (used.count(cands[i])) continue;
        used.insert(cands[i]);
        path.push_back(cands[i]);
        backtrack(vec, path, cands, i + 1, target - cands[i]);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ret = {};
    vector<int> path = {}; 
    sort(candidates.begin(), candidates.end());
    backtrack(ret, path, candidates, 0, target);
    return ret;
}

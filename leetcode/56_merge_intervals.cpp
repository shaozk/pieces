// 56.合并区间
//
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size(), l, r;
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; ++i) {
        l = intervals[i][0];
        r = intervals[i][1];
        if (i == 0 || result.back()[1] < l) {
            result.push_back({l, r});
        } else {
            result.back()[1] = max(result.back()[1], r);
        }
    }
    return result;


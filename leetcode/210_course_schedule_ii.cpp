// 210.课程表II
//
// 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
// * 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int n = prerequisites.size();
    vector<vector<int>> edges(numCourses);
    vector<int> indeg(numCourses);
    for (const auto& info : prerequisites) {
        int a = info[0], b = info[1];
        edges[b].push_back(a);
        ++indeg[a];
    }
    queue<int> que;
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) que.push(i);
    }
    vector<int> ret;
    while (!que.empty()) {
        int b = que.front(); que.pop();
        ret.push_back(b);
        for (auto a : edges[b]) {
            --indeg[a];
            if (indeg[a] == 0) {
                que.push(a);
            }
        }
    }
    if (ret.size() == numCourses) {
        return ret;
    } else {
        return {};
    }
}

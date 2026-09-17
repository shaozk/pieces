// 207.课程表
//
// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (prerequisites.empty()) return true;
    queue<int> que;
    vector<vector<int>> edges(numCourses);
    vector<int> indeg(numCourses);
    for (const auto info : prerequisites) {
        int a = info[0], b = info[1];
        edges[b].push_back(a);
        ++indeg[a];
    }
    for (int i = 0; i < numCourses; ++i) {
        if (indeg[i] == 0) {
            que.push(i);
        }
    }
    int visited = 0;
    while (!que.empty()) {
        ++visited;
        int b = que.front(); que.pop();
        for (auto a : edges[b]) {
            --indeg[a];
            if (indeg[a] == 0) que.push(a);
        }
    }
    return visited == numCourses;
}


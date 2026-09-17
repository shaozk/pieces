// 630.课程表III
//
// 这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。
// 你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
// 返回你最多可以修读的课程数目。

int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), [] (vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
    priority_queue<int> pque;
    int total = 0;
    for (const auto& course : courses) {
        int ti = course[0], di = course[1];
        pque.push(ti);
        total += ti;
        if (total > di) {
            total -= pque.top();
            pque.pop();
        }
    }
    return pque.size();
}


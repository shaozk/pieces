// 739.每日温度
//
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ret(n, 0);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            int prei = stk.top();
            ret[prei] = i - prei;
            stk.pop();
        }
        stk.push(i);
    }
    return ret;
}

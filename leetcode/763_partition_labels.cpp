// 763.划分字母区间
//
// 给你一个字符串 s 。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。例如，字符串 "ababcc" 能够被分为 ["abab", "cc"]，但类似 ["aba", "bcc"] 或 ["ab", "ab", "cc"] 的划分是非法的。
// 注意，划分结果需要满足：将所有划分结果按顺序连接，得到的字符串仍然是 s 。
// 返回一个表示每个字符串片段的长度的列表。


vector<int> partitionLabels(string s) {
    vector<int> ret;
    int n = s.size();
    int last[26];
    int start = 0, end = 0;
    for (int i = 0; i < n; ++i) {
        last[s[i] - 'a'] = i;
    }
    for (int i = 0; i < n; ++i) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) {
            ret.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return ret;
}


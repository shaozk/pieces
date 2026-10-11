// 139.单词拆分
//
// 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    unordered_set<string> set;
    for (auto word : wordDict) {
        set.insert(word);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp[j] && set.find(s.substr(j, i - j)) != set.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}


// 438.找到字符串中所有字母异位词
//
// 给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

vector<int> findAnagrams(string s, string p) {
    vector<int> ans = {};
    int sn = s.size(), pn = p.size();
    if (sn < pn) return ans;
    vector<int> need(26), window(26);
    for (int i = 0; i < pn; ++i) {
        ++need[p[i] - 'a'];
        ++window[s[i] - 'a']; 
    }
    if (need == window) ans.push_back(0);
    for (int i = 0; i < sn - pn; ++i) {
        --window[s[i] - 'a'];
        ++window[s[i + pn] - 'a'];
        if (need == window) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}

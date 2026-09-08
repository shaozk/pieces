// 3.无重复字符的最长子串
//
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

int lengthOfLongestSubstring(string s) {
    unordered_set<int> set;
    int n = s.size(), left = 0, right = -1, ans = 0;
    while (left < n) {
        if (left != 0) {
            set.erase(s[left - 1]);
        }
        while (right + 1 < n && !set.count(s[right + 1])) {
            set.insert(s[right + 1]);
            ++right;
        }
        ans = max(ans, right - left + 1);
        ++left;
    }
    return ans;
}
 


// 49.字母异位词
// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }
        vector<vector<string>> result;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            result.push_back(it->second);
        }
        return result; 
    }
};

// 17.电话号码的字母组合
//
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。


vector<string> tel = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

void backtrack(vector<string>& vec, string& path, int ind, const string& digits) {
    if (digits.size() == ind) {
        vec.push_back(path);
        return;
    }
    string alpha = tel[(int)(digits[ind] - '0')];
    for (char a : alpha) {
        path.push_back(a);
        backtrack(vec, path, ind + 1, digits);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ret;
    string path;
    backtrack(ret, path, 0, digits);
    return ret;
}


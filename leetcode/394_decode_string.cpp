// 39.字符串解码
//
// 给定一个经过编码的字符串，返回它解码后的字符串。
// 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
// 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
// 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
// 测试用例保证输出的长度不会超过 105。

string decodeString(string s) {
    stack<string> stks;
    stack<int> stkn;
    string curs;
    int curn;
    for (char c : s) {
        if (isdigit(c)) {
            curn = curn * 10 + (c - '0');
        } else if (c == '[') {
            stkn.push(curn);
            stks.push(curs);
            curs.clear();
            curn = 0;
        } else if (c == ']') {
            int n = stkn.top(); stkn.pop();
            string prev = stks.top(); stks.pop();
            for (int i = 0; i < n; ++i) {
                prev += curs;
            }
            curs = move(prev);
        } else {
            curs += c;
        }
    }
    return curs;
}



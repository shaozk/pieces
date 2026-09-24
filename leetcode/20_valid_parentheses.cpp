// 20.有效的括号
//
// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
// 有效字符串需满足：
// 1. 左括号必须用相同类型的右括号闭合。
// 2. 左括号必须以正确的顺序闭合。
// 3. 每个右括号都有一个对应的相同类型的左括号。

bool isValid(string s) {
    if (s.size() % 2 == 1) return false;
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };
    stack<char> stk;
    for (char c : s) {
        if (pairs.count(c)) {
            if (stk.empty() || stk.top() != pairs[c]) {
                return false;
            }
            stk.pop();
        } else {
            stk.push(c);
        }
    }
    return stk.empty();
}


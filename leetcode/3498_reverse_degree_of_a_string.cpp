// 3498.字符串的反转度
//
// 给你一个字符串 s，计算其 反转度。
// 反转度的计算方法如下：
// 1 对于每个字符，将其在 反转 字母表中的位置（'a' = 26, 'b' = 25, ..., 'z' = 1）与其在字符串中的位置（下标从1 开始）相乘。
// 2 将这些乘积加起来，得到字符串中所有字符的和。
// 返回 反转度。


int reversePos(char c) {
    return 26 - (c - 'a');
}
int reverseDegree(string s) {
    int ret = 0;
    for (int i = 0; i < s.length(); ++i) {
        ret += reversePos(s[i]) * (i + 1);
    }
    return ret;
}


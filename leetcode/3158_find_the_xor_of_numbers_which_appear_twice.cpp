// 3158.求出出现两次数字的 XOR 值
// 
// 给你一个数组 nums ，数组中的数字 要么 出现一次，要么 出现两次。
// 请你返回数组中所有出现两次数字的按位 XOR 值，如果没有数字出现过两次，返回 0 。

int duplicateNumbersXOR(vector<int>& nums) {
    int ret = 0;
    unordered_set<int> set;
    for (int item : nums) {
        if (set.find(item) != set.end()) {
            ret ^= item;
        } else {
            set.insert(item);
        }
    }
    return ret;
}


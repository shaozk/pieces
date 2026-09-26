// 260.只出现一次的数字 III
//
// 给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
// 你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。


vector<int> singleNumber(vector<int>& nums) {
    int xors = 0;
    for (int item : nums) {
        xors ^= item;
    }
    int lsb = xors == INT_MIN ? INT_MIN : xors & (-xors);
    int ret1 = 0, ret2 = 0;
    for (int item : nums) {
        if (item & lsb) {
            ret1 ^= item;
        } else {
            ret2 ^= item;
        }
    }
    return {ret1, ret2};
}


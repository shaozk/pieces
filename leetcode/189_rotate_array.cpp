// 189.旋转数组
//
// 给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

void reverse(vector<int>& nums, int l, int r) {
    while (l < r) {
        swap(nums[l++], nums[r--]);
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
    
}


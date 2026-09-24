// 912.排序数组
//
// 给你一个整数数组 nums，请你将该数组升序排列。
// 你必须在 不使用任何内置函数 的情况下解决问题，时间复杂度为 O(nlog(n))，并且空间复杂度尽可能小。


void quicksort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    int x = nums[m];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (nums[i] < x);
        do j--; while (nums[j] > x);
        if (i < j) swap(nums[i], nums[j]);
    }
    quicksort(nums, l, j);
    quicksort(nums, j + 1, r);
}

vector<int> sortArray(vector<int>& nums) {
    int n = nums.size();
    quicksort(nums, 0, n - 1);
    return nums;
}



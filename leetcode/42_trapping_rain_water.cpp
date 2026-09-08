// 4.接雨水
// 
// 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。


int trap(vector<int>& height) {
    int ans = 0;
    int left = 0, right = height.size() - 1;
    int maxLeft = 0, maxRight = 0;
    while (left < right) {
        maxLeft = max(maxLeft, height[left]);
        maxRight = max(maxRight, height[right]);
        if (height[left] < height[right]) {
            ans += (maxLeft - height[left]);
            ++left;
        } else {
            ans += (maxRight - height[right]);
            --right;
        }
    }
    return ans;
}

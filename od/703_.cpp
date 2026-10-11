// 703.少儿爬山积分闯关游戏
//
// 题目描述
// 山路一共设有n个关卡、按1~n顺序排列。当前位干1号关卡,必须按照关卡从小到大闯关,且必须到达最后第n号关卡才算寻宝成
// 功。每个关卡都有对应的宝藏分值(可能为负数),经过当前关卡即可获得该关卡分值,分数持续累加。
// 
// 移动规则:
// 1.从当前关卡,下一次只能在前方1关或者2关处打卡;
// 2.限制规则:不能连续两次都一次性跳2关,违反该规则的路终无效
// 请求出:所有合法路线中,能够收集到的最大累加总分。
// 
// 输入描述
// 参数1:整数n,代表关卡数量
// 参数2:整数数组 ,依次表示第1~n关的宝藏分值
// 1≤n≤20
// 每关分值:-999svals999
// 
// 输出描述
// 输出一个整数,代表合法路线的最大累加得分。


#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n + 1);
  for (int i = 1; i <= n; ++i) cin >> nums[i];

  const int NEG = INT_MIN / 2;
  vector<vector<int>> dp(n + 1, vector<int>(2, NEG));
  dp[1][0] = nums[1];
  for (int i = 1; i <= n; ++i) {
    for (int flag = 0; flag <= 1; ++flag) {
      if (dp[i][flag] == NEG) continue;
      if (i + 1 <= n) {
        dp[i + 1][flag] = max(dp[i + 1][0], dp[i][flag] + nums[i + 1]);
      }
      if (flag == 0 && i + 2 <= n) {
        dp[i + 2][flag] = max(dp[i + 2][1], dp[i][flag] + nums[i + 2]);
      }
    }
  }

  cout << max(dp[n][0], dp[n][1]) << endl;
  return 0;
}

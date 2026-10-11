// 702.仓库货物有序出库
//
// 题目描述
// 某仓储中心中有一个货物堆放区,货物编号按乱序堆叠存放,只能从从顶部取货(后进先出),管理员需要将货物按编号从
// 小到大取出。
// 仓库设有1个临时区,可将主库顶部货物依次转移到临时区,临时区区也为堆叠存放(后进先出);主库或临时区顶部货物
// 均可直接出库;其他操作(包括主库→临时区和临时区→主库)均为"暂存"操作;请计算至少需要多少次暂存操作,能
// 保证所有货物按编号从小到大依次出库。
// 
// 补充说明:
// * 临时区有且只有一个
// * 出库顺序必须是严格升序,每件出库货物的编号必须大于i前一件
// * 题目保证所有货物编号互不重复(可能为负数,编号数字不保证通纯
// * 题目保证总能找到一种合法的操作方案完成有序出库
// 
// 输入描述
// 参数1:一个整数n(1<n<1000),表示货物的总数量。
// 参数2:整数数组[a1,a2,...,an](-1000<ai<1000),表示货物的编号,从左到右依次对应货物堆底部到顶部。
// 
// 输出描述
// 一个整数,表示最少暂存操作次数。


#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];

  vector<int> mstk = nums;
  vector<int> tstk;
  vector<int> sorted = nums;
  sort(sorted.begin(), sorted.end());

  int ret = 0, idx = 0;
  while (idx < n) {
    int cur = sorted[idx];
    if (!mstk.empty() && mstk.back() == cur) {
      mstk.pop_back();
      ++idx;
    } else if (!tstk.empty() && tstk.back() == cur) {
      tstk.pop_back();
      ++idx;
    } else {
      bool in_main = false;
      for (auto x : mstk) {
        if (x == cur) {
          in_main = true;
          break;
        }
      }
      if (in_main) {
        tstk.push_back(mstk.back());
        mstk.pop_back();
        ++ret;
      } else {
        mstk.push_back(tstk.back());
        tstk.pop_back();
        ++ret;
      }
    }
  }
  cout << ret << endl;
  return 0;
}

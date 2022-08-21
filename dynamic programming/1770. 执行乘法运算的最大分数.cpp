#include <bits/stdc++.h>
#include <vector>

using namespace std;

/*
给你两个长度分别 n 和 m 的整数数组 nums 和 multipliers ，其中 n >= m ，数组下标 从 1 开始 计数。

初始时，你的分数为 0 。你需要执行恰好 m 步操作。在第 i 步操作（从 1 开始 计数）中，需要：

选择数组 nums 开头处或者末尾处 的整数 x 。
你获得 multipliers[i] * x 分，并累加到你的分数中。
将 x 从数组 nums 中移除。
在执行 m 步操作后，返回 最大 分数。

 

示例 1：

输入：nums = [1,2,3], multipliers = [3,2,1]
输出：14
解释：一种最优解决方案如下：
- 选择末尾处的整数 3 ，[1,2,3] ，得 3 * 3 = 9 分，累加到分数中。
- 选择末尾处的整数 2 ，[1,2] ，得 2 * 2 = 4 分，累加到分数中。
- 选择末尾处的整数 1 ，[1] ，得 1 * 1 = 1 分，累加到分数中。
总分数为 9 + 4 + 1 = 14 。
示例 2：

输入：nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
输出：102
解释：一种最优解决方案如下：
- 选择开头处的整数 -5 ，[-5,-3,-3,-2,7,1] ，得 -5 * -10 = 50 分，累加到分数中。
- 选择开头处的整数 -3 ，[-3,-3,-2,7,1] ，得 -3 * -5 = 15 分，累加到分数中。
- 选择开头处的整数 -3 ，[-3,-2,7,1] ，得 -3 * 3 = -9 分，累加到分数中。
- 选择末尾处的整数 1 ，[-2,7,1] ，得 1 * 4 = 4 分，累加到分数中。
- 选择末尾处的整数 7 ，[-2,7] ，得 7 * 6 = 42 分，累加到分数中。
总分数为 50 + 15 - 9 + 4 + 42 = 102 。
 

提示：

n == nums.length
m == multipliers.length
1 <= m <= 103
m <= n <= 105
-1000 <= nums[i], multipliers[i] <= 1000
*/

/* dp思路
f[i][j] 代表 nums 前i个数 和 后j个数 可组成的最大数
初始化状态：f[0][0] = 0
f[i][0] = f[i - 1][0] + num[i - 1] * multipliers[i - 1]
f[0][j] = f[0][j - 1] + nums[n - j] * multipliers[i - 1]
转移方程
f[i][j] = max(f[i - 1][j] + nums[i - 1] * multipliers[i - 1 + j], f[i][j - 1] + nums[n - j] * multipliers[i + j - 1])
结果
i + j == m时，max(d[i][j])
*/
int maximumScore(vector<int> &nums, vector<int> &multipliers)
{
  int n = nums.size(), m = multipliers.size(), ans = INT_MIN;
  int f[1000 + 5][1000 + 5];
  f[0][0] = 0;
  for (int i = 1; i <= m; ++i)
    f[i][0] = f[i - 1][0] + nums[i - 1] * multipliers[i - 1];
  for (int j = 1; j <= m; ++j)
    f[0][j] = f[0][j - 1] + nums[n - j] * multipliers[j - 1];

  for (int i = 1; i <= m; ++i)
  {

    for (int j = 1; i + j <= m; ++j)
    {

      f[i][j] = max(f[i - 1][j] + nums[i - 1] * multipliers[i + j - 1],
                    f[i][j - 1] + nums[n - j] * multipliers[i + j - 1]);

      if (i + j == m)
        ans = max(ans, f[i][m - i]);
    }
  }

  for (int i = 0; i <= m; i++)
  {
    ans = max(ans, f[i][m - i]);
  }
  return ans;
}

/*
827. 最大人工岛
给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。

返回执行此操作后，grid 中最大的岛屿面积是多少？

岛屿 由一组上、下、左、右四个方向相连的 1 形成。



示例 1:

输入: grid = [[1, 0], [0, 1]]
输出: 3
解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
示例 2:

输入: grid = [[1, 1], [1, 0]]
输出: 4
解释: 将一格0变成1，岛屿的面积扩大为 4。
示例 3:

输入: grid = [[1, 1], [1, 1]]
输出: 4
解释: 没有0可以让我们变成1，面积依然为 4。


提示：

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] 为 0 或 1
*/

#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
  int n, m;
  vector<int> p, sz; // p存并查集，sz存所在图的大小

  // 并查集模板
  int find(int x)
  {
    if (p[x] != x)
      p[x] = find(p[x]);
    return p[x];
  }

  // 二维坐标一维计算模板
  int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
  int get(int x, int y)
  {
    return x * m + y;
  }

  int largestIsland(vector<vector<int>> &grid)
  {
    n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n * m; i++)
      p.push_back(i), sz.push_back(1);

    int res = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)

        // 如果点是1，上下左右走，计算该点图大小并维护并查集
        if (grid[i][j])
        {
          int a = get(i, j);
          for (int k = 0; k < 4; k++)
          {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y])
            {
              int b = get(x, y);
              // 如果相同则合并，并且更新所在图大小
              if (find(a) != find(b))
              {
                sz[find(b)] += sz[find(a)];
                p[find(a)] = find(b);
              }
            }
          }
          // 防止全是1的情况
          res = max(res, sz[find(a)]);
        }

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        // 遍历是0的点
        if (!grid[i][j])
        {
          // 遍历上下左右四个方向，map去重--上下左右可能已经是连通的了
          map<int, int> hash;
          for (int k = 0; k < 4; k++)
          {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y])
            {
              int a = get(x, y);
              hash[find(a)] = sz[find(a)];
            }
          }

          // 连通求和，+1--本身
          int s = 1;
          for (auto [k, v] : hash)
            s += v;
          res = max(res, s);
        }

    return res;
  }
};

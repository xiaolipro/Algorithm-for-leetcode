#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  void dfs(vector<vector<int>> &grid, int x, int y)
  {
    grid[x][y] = 2;

    for (int i = 0; i < 4; i++)
    {
      int tx = dx[i] + x;
      int ty = dy[i] + y;
      if (tx < 0 || ty < 0 || tx >= grid.size() || ty >= grid[0].size() || grid[tx][ty] != 1)
        continue;
      dfs(grid, tx, ty);
    }
  }

  int count(vector<vector<int>> &grid)
  {
    int res = 0;

    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
        {
          res++;
          dfs(grid, i, j);
        }
      }
    }

    // 还原
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 2)
        {
          grid[i][j] = 1;
        }
      }
    }

    return res;
  }

  int minDays(vector<vector<int>> &grid)
  {
    // 0
    if (count(grid) != 1)
      return 0;

    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        if (grid[i][j] == 1)
        {
          grid[i][j] = 0;
          if (count(grid) != 1)
            return 1;
          grid[i][j] = 1;
        }
      }
    }

    return 2;
  }
};

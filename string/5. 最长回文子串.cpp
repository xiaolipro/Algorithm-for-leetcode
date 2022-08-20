#include <bits/stdc++.h>

using namespace std;

/*
示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：
输入：s = "cbbd"
输出："bb"

提示：
1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/
int main()
{
  string s;
  cin >> s;

  // 中心拓展法，时间复杂度O(N^2)

  // "a"
  string res = s.substr(0, 1);

  for (int i = 0; i < s.length(); i++)
  {
    // "abccba"
    int x = i, y = i + 1;
    while (x >= 0 && y < s.length() && s[x] == s[y])
    {
      if (y - x + 1 > res.length())
        res = s.substr(x, y - x + 1);
      x--, y++;
    }

    // "aba"
    x = i - 1, y = i + 1;
    while (x >= 0 && y < s.length() && s[x] == s[y])
    {
      if (y - x + 1 > res.length())
        res = s.substr(x, y - x + 1);
      x--, y++;
    }
  }

  cout << res << endl;
}

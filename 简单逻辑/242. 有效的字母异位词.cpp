#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  /*
  给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

  注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

   

  示例 1:

  输入: s = "anagram", t = "nagaram"
  输出: true
  示例 2:

  输入: s = "rat", t = "car"
  输出: false
   

  提示:

  1 <= s.length, t.length <= 5 * 104
  s 和 t 仅包含小写字母

  来源：力扣（LeetCode）
  链接：https://leetcode.cn/problems/valid-anagram
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
  */

  // 朴素的排序nlogn也是可以的，这里使用hash可以做到n，由于题目规定了只给小写字母所以hash都不用了，直接映射。
  bool isAnagram(string s, string t)
  {
    if (s.length() != t.length())
      return false;
    vector<int> vec(26);
    for (auto x : s)
      vec[x - 'a']++;
    for (auto x : t)
    {
      vec[x - 'a']--;
      if (vec[x - 'a'] < 0)
        return false;
    }

    return true;
  }
};

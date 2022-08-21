#include <iostream>
#include <string>

using namespace std;

/*
给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子由若干用 单个空格 分隔的单词组成。请你检查检索词 searchWord 是否为句子 sentence 中任意单词的前缀。

如果 searchWord 是某一个单词的前缀，则返回句子 sentence 中该单词所对应的下标（下标从 1 开始）。如果 searchWord 是多个单词的前缀，则返回匹配的第一个单词的下标（最小下标）。如果 searchWord 不是任何单词的前缀，则返回 -1 。

字符串 s 的 前缀 是 s 的任何前导连续子字符串。

 

示例 1：

输入：sentence = "i love eating burger", searchWord = "burg"
输出：4
解释："burg" 是 "burger" 的前缀，而 "burger" 是句子中第 4 个单词。
示例 2：

输入：sentence = "this problem is an easy problem", searchWord = "pro"
输出：2
解释："pro" 是 "problem" 的前缀，而 "problem" 是句子中第 2 个也是第 6 个单词，但是应该返回最小下标 2 。
示例 3：

输入：sentence = "i am tired", searchWord = "you"
输出：-1
解释："you" 不是句子中任何单词的前缀。
*/

// 思路 split forech  时空复杂度均O(N)
// 使用双指针优化空间到O(1)
bool isPrefix(const string &sentence, string &searchWord, int l, int r)
{
  cout << l << ' ' << r << endl;
  if (searchWord.size() > r - l + 1)
    return false;
  for (int i = 0; i < searchWord.size(); i++)
  {
    if (sentence[l++] != searchWord[i])
      return false;
  }

  return true;
}
int isPrefixOfWord(string sentence, string searchWord)
{
  int res = -1;

  int l = 0, r = 0, idx = 1;
  for (int i = 0; i < sentence.size(); idx++, i++)
  {
    while (i < sentence.size() && sentence[i] != ' ')
      r++, i++;

    if (isPrefix(sentence, searchWord, l, r - 1))
      return idx;
    r++;
    l = r;
  }

  return res;
}

int main(int argc, char const *argv[])
{
  auto sentence = "i love eating burger", searchWord = "burg";
  auto res = isPrefixOfWord(sentence, searchWord);
  cout << "res is: " << res << endl;
  return 0;
}

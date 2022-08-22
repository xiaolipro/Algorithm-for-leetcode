#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  int pairSum(ListNode *head)
  {
    vector<int> nums(10e5 + 10, 0);
    int n = 0;
    for (auto i = head; i != nullptr; i = i->next)
    {
      nums[n++] = i->val;
    }

    int res = 0;

    for (int i = 0; i <= (n / 2) - 1; i++)
    {
      res = max(res, nums[i] + nums[n - 1 - i]);
    }

    return res;
  }

  // 用快慢指针+链表翻转的做法可以把空间开销降低到O(1)
  int pairSum2(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;

    // 用快慢指针找到中心点
    while (fast->next && fast->next->next)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // 翻转列表的起点是慢指针的next
    ListNode *t = slow->next;
    while (t->next)
    {
      // 1->2->3
      auto cur = t->next;     // 暂存next 2
      t->next = cur->next;    // 1->3
      cur->next = slow->next; // 2->1
      slow->next = cur;       // 2->1->3
    }

    auto x = head;
    auto y = slow->next; //慢指针的next是翻转列表的起点
    int res = 0;
    while (y)
    {
      res = max(res, x->val + y->val);
      x = x->next;
      y = y->next;
    }

    return res;
  }
};

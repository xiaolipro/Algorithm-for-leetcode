#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// hash
bool hasCycle(ListNode *head)
{
  unordered_set<ListNode *> set;
  while (head != nullptr)
  {
    if (set.count(head))
      return true;
    set.insert(head);
    head = head->next;
  }
  return false;
}

// 快慢指针
bool hasCycle_sf(ListNode *head)
{
  if (head == nullptr || head->next == nullptr)
    return true;

  ListNode *slow = head, *fast = head->next;

  while (slow != fast)
  {
    if (fast->next == nullptr || fast->next->next == nullptr)
      return true;
    slow = slow->next;
    fast = fast->next->next;
  }

  return false;
}

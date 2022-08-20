#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *f(vector<int> &nums, int l, int r)
{
  if (l > r)
  {
    return nullptr;
  }
  int idx = l;
  for (int i = l + 1; i <= r; i++)
  {
    if (nums[i] > nums[idx])
    {
      idx = i;
    }
  }

  TreeNode *node = new TreeNode(nums[idx]);
  node->left = f(nums, l, idx - 1);
  node->right = f(nums, idx + 1, r);

  return node;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{

  return f(nums, 0, nums.size() - 1);
}

// bfs
void output(TreeNode *node)
{
  queue<TreeNode *> q;
  q.push(node);

  while (!q.empty())
  {
    auto *t = q.front();
    q.pop();
    cout << t->val << ' ';
    if (t->left)
      q.push(t->left);
    if (t->right)
      q.push(t->right);
  }
}

int main()
{
  vector<int> nums;

  int x;
  while (cin >> x)
  {
    nums.push_back(x);
  }

  output(constructMaximumBinaryTree(nums));
}

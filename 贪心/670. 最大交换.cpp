/*
670. 最大交换
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。
注意:

给定数字的范围是 [0, 108]
*/


// 这题有点像双指针
class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num), res = "";
        int n = str.size();
        int t = n - 1, l = -1, r = -1;
        // 从右往左遍历
        for (int i = n - 1; i >= 0; i -- ) {
             // 维护最大的数（最值得被交换）
             if (str[i] > str[t]) t = i;
             // 只有左边的数小于最大的数才有更新的意义
             else if (str[i] < str[t]) {
                 l = i, r = t;
             }
        }

        if (l == -1) return num;

        swap(str[l],str[r]);
        return atoi(str.c_str());

    }
};
/**
 * LeetCode 2134. Minimum Swaps to Group All 1's Together II
 *
 * 标签：定长滑窗（fixed-length sliding window）
 *
 * 题目特点：
 * - 输入是一个环形数组（circular array），意味着滑动窗口可以“ wrap around ”末尾回到开头。
 * - 目标是把所有 1 集中在一起，需要最少的交换操作。
 *
 * 解题思路：
 * - 先统计数组中 1 的总数量 k。
 * - 任何能够把 k 个 1 连在一起的区间长度都是 k（即窗口大小为 k）。
 * - 将问题转换为“在长度为 k 的窗口内找到 0 的最少个数”。
 *   由于交换 0 和 1 的次数等于窗口内 0 的数量，因此最小 0 数即为答案。
 * - 由于数组是环形的，我们把索引 i 映射到 [0, n-1] 范围：使用 i % n。
 * - 使用滑动窗口在长度为 2*n 的模拟区间上遍历，使窗口可以跨越边界。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // 统计数组中 1 的总数 k
        int k = 0;
        for (auto val : nums) {
            if (val == 1) k++;
        }
        // 如果没有 1，则不需要交换
        if (k == 0) return 0;

        
        int n = nums.size();
        int zerosInWindow = 0;
        int ans = INT_MAX;

        // 在长度为 2*n 的区间上滑动窗口，以模拟环形数组
        // 窗口大小为 k（即 1 的总数），目标是找到窗口内 0 的最小值
        for (int i = 0; i < 2 * n; i++) {
            // 窗口右端入队：如果是 0，则计数
            if (nums[i % n] == 0) zerosInWindow++;

            // 还未形成完整窗口时，继续扩展
            if (i - k + 1 < 0) continue;

            // 窗口已形成，更新答案
            ans = min(ans, zerosInWindow);

            // 窗口左端出队：如果是 0，则减计数
            int leftIdx = i - k + 1;
            if (nums[leftIdx % n] == 0) zerosInWindow--;
        }

        return ans;
    }
};
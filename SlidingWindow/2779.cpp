/**
 * 力扣2779 不定长滑动窗口 求最长子数组
 * 
 * 题目最后求一个最长子数组，因为最后数组中都是一个值，所以可以先对数组排序
 * 排完序后，每一个元素可以看作是一个数组。
 * [left-k,left+k],[right-k,right+k],想要满足题意，必须要
 * left+k>=right-k  即  right - left <= 2k ;
 * 这样就可以转化为不定长的滑动窗口问题。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        ranges::sort(nums.begin(),nums.end());
        int left = 0;
        int ans = 0;
        for(int right=0;right<nums.size();right++){
            while(nums[right]-nums[left]>2*k)
            {
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};
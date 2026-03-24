/*
力扣3795 不定长滑动窗口 越短越合法

整体上还是和滑动窗口一样，先将元素纳入窗口，如果现在
窗口合法，就缩短窗口看看能不能更短

和越长越合法的区别：
1.越长越合法的while是当窗口非法时循环，循环结束，窗口合法，更新答案
2.越短越合法的while是当窗口合法时循环，每个窗口都是合法的
因此更新答案要在while内部

*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        unordered_map<int,int> hm;
        for(int right=0;right<nums.size();right++)
        {
            int x = nums[right];
            hm[x]++;
            if(hm[x]==1){
                sum+=x;
            }
            while(sum>=k){
                ans = min(ans,right-left+1);
                int out = nums[left];
                hm[out]--;
                if(hm[out]==0) sum-=out;
                left++;
            }

        }

        return ans==INT_MAX?-1:ans;
    }
};

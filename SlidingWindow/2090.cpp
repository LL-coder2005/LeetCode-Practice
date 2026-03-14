/**
 * 力扣2090题目 定长型滑窗
 * 本质是维护一个长度为2*k+1的滑窗
 * 入： 将nums[right]加到sum中
 * 更新：记录ans数组
 * 出： 把左侧点移出窗口，同时sum-=nums[left]
 * 
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int left=0;
        int right = 0;
        int n = nums.size();
        vector<int> ans(n,-1);
        long long sum = 0;
        int len = 2*k+1;
        for(;right<n;right++){
            sum+=nums[right];
            if(right-left+1<len){
                continue;
            }
            ans[(right+left)/2]=sum/len;
            sum-=nums[left];
            left++;
        }

        return ans;
    }
};
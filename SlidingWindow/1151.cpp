/**
 * 力扣1151 用最小交换次数来组合所有的1
 * 把思维逆转一下，在以1的数量为长度的窗口中，0的最少次数即为答案
 * 先统计数组中1的数量，确定窗口的大小num
 * 在num长度的滑窗中统计0的最少出现次数
 */

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& data) {
        //确定窗口的大小
        int num = 0;
        for(auto val:data){
            if(val==1) num++;
        }
        //如果数组里没有1，则直接返回0
        if(num==0) return 0;
        int ans = INT_MAX;
        int n = 0;
        for(int right = 0;right<data.size();right++){
            if(data[right]==0) n++;
            if(right-num+1<0) continue;
            ans = min(ans,n);
            if(data[right-num+1]==0) n--;
        }
        return ans;
    }
};
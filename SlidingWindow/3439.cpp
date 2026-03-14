/**
 * 力扣3439 转换为定长型滑动窗口
 * 
 * 题目要求通过平移k个会议时间得到一段空闲时间的最大值
 * 且不能改变会议的先后顺序。
 * 
 * 分析：平移k个会议，即找到k+1个空闲时间合并，且会议顺序不变
 * 那么题目变为有n+1个空闲时间，连续合并k+1个空闲时间，找出最大值
 * 长度为k+1的滑窗
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        //求出每段空闲时间
        startTime.push_back(eventTime);
        endTime.insert(endTime.begin(),0);
        vector<int> time;
        for(int i=0;i<startTime.size();i++){
            time.push_back(startTime[i]-endTime[i]);
        }

        int sum = 0;
        int ans = -INT_MAX;
        for(int i=0;i<time.size();i++){
            sum+=time[i];
            if(i-(k+1)+1<0) continue;
            ans = max(ans,sum);
            int left = i-(k+1)+1;
            sum-=time[left];
        }
        return ans;
    }
};
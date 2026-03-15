/**
 * 力扣3679 定长滑动窗口
 * 
 * 特殊点：
 *  1.与普通的滑窗相比，不需要等待窗口成型。因为题目中所说的
 * 考虑天数范围为 [max(1, i - w + 1), i]。
 *  2.为了保证丢弃的次数最少，当到达上限时，需要将最新的那次 “软删除”
 *  如果真实的在哈希表中hm[right]--。那么当这个点从窗口左侧删除时，会
 *  删除两遍。因此，需要将该值设为一个不可能的数 如负数
 *  3.最后的结果是累加的，不是取一个最小值
 *  
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 函数：计算最少丢弃次数
    // 参数：arrivals - 到达时间数组，w - 窗口大小，m - 最大允许次数
    // 返回：最少丢弃次数
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        // 使用哈希表记录每个到达时间的出现次数
        unordered_map<int,int> hm;
        // 答案：丢弃次数
        int ans = 0;
        // 遍历每个到达时间
        for(int right=0;right<arrivals.size();right++){
            // 入窗口：增加当前到达时间的计数
            hm[arrivals[right]]++;

            // 没有判断窗口是否成型，因为窗口总是从max(1, i-w+1)开始

            // 更新：如果当前到达时间超过m次，需要丢弃
            if(hm[arrivals[right]]>m){
                // 丢弃次数加1
                ans++;
                // 软删除：减少计数，但设为-1防止后续删除时重复减少
                hm[arrivals[right]]--;
                arrivals[right] = -1;
                
            }

            // 出窗口：如果窗口左侧超出范围，减少对应计数
            if(right-w+1>=0)
            hm[arrivals[right-w+1]]--;
        }
        // 返回总丢弃次数
        return ans;
    }
};
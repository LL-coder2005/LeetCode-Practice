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
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int> hm;
        int ans = 0;
        for(int right=0;right<arrivals.size();right++){
            //入
            hm[arrivals[right]]++;

            //没有判断窗口是否成型

            //更新
            if(hm[arrivals[right]]>m){
                ans++;
                //软删除，设为一个不影响的值，防止删除两遍
                hm[arrivals[right]]--;
                arrivals[right] = -1;
            }

            //出
            if(right-w+1>=0)
            hm[arrivals[right-w+1]]--;
        }
        return ans;
    }
};
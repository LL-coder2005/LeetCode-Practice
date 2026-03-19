/**
 * 力扣003 不定长滑窗 求最长子数组
 * 不断的把right元素添加到窗口中
 * 如果此时窗口不合法，那么不断的把left元素移出窗口，直到窗口再次合法
 * 把答案更新
 * 返回答案
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        unordered_map<char,int> hm;
        int ans = 0;
        for(;right<s.size();right++){
            hm[s[right]]++;
            while(hm[s[right]]>1){
                hm[s[left]]--;
                if(hm[s[left]]==0) hm.erase(s[left]);
                left++;
            }
            int temp = right-left+1;
            ans = max(ans,temp);
        }
        return ans;
    }
};
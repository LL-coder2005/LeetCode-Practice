/**
 * 力扣3694 定长滑窗
 * 
 * 逆向思维，站在最终点思考问题
 * 删除子字符串后的不同终点转变为子字符串的种类数
 * 涉及到种数，用set去重
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctPoints(string s, int k) {
        int x = 0;
        int y = 0;
        set<pair<int,int>> hm;
        int ans=0;
        int left;
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
            }
            left = i-k+1;
            if(left<0){
                continue;
            }
            hm.insert({x,y});
            switch(s[left]){
                case 'U': y--; break;
                case 'D': y++; break;
                case 'L': x++; break;
                case 'R': x--; break;
            }
        }

        return hm.size();
    }
};
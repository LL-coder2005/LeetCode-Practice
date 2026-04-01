#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>> hm;
        for(int i=0;i<nums.size();i++){
            hm[nums[i]].push_back(i);
        }
        int n = nums.size();
        for(auto& [_,p]:hm){
            int q = p[0];
            p.insert(p.begin(),p.back()-n);
            p.push_back(q+n);
        }
        for(auto& i:queries){
            auto& p = hm[nums[i]];
            if(p.size()==3) i = -1;
            else{
                int j = lower_bound(p.begin(),p.end(),i)-p.begin();
                i = min(p[j+1]-i,i-p[j-1]);  
            } 
        }

        return queries;
    }
};
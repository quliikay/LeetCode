/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int curCover = 0;
        int nextCover = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            nextCover = max(nextCover, i+nums[i]);
            if(i==curCover){
                if(i!=nums.size()-1){
                    ans++;
                    curCover = nextCover;
                }else
                    break;
            }
        }
        return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> path;
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return ans;
    }
    bool isPrime(string s, int left, int right){
        while(left<right){
            if(s[left++]!=s[right--])
                return false;
        }
        return true;
    }
    void backtracking(string s, int startIndex){
        if(startIndex==s.size()){
            ans.emplace_back(path);
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isPrime(s, startIndex, i)){
                string a = s.substr(startIndex, i - startIndex + 1);
                path.emplace_back(a);
                backtracking(s, i+1);
                path.pop_back();
            }
        }
    }
};
// @lc code=end

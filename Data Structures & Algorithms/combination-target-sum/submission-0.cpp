#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        dfs(candidates, 0, target, comb, res);
        return res;
    }

private:
    void dfs(const vector<int>& candidates, int start, int target,
             vector<int>& comb, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(comb);
            return;
        }
        for (int i = start; i < (int)candidates.size(); ++i) {
            int val = candidates[i];
            if (val > target) break;
            comb.push_back(val);
            dfs(candidates, i, target - val, comb, res); // allow reuse of i
            comb.pop_back();
        }
    }
};



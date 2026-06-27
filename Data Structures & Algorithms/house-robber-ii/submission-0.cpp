class Solution { public: int rob(vector<int>& nums) { 
    int n = nums.size();
     if (n == 0) return 0;
      if (n == 1) return nums[0]; 
      auto robLinear = [&](int l, int r) -> int { 
        int prev2 = 0, prev = 0; for (int i = l; i <= r; ++i) {
         int take = prev2 + nums[i]; 
         int cur = max(prev, take); 
         prev2 = prev; prev = cur; } 
         return prev; };
 return max(robLinear(0, n - 2), robLinear(1, n - 1));
  } };
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int n = nums.size();
        int pre = 1;
        int suf = 1;
        for(int i = 0; i<n;i++){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;
            pre *= nums[i];
            suf *= nums[n-i-1];
            maxProd = max(max(pre,suf),maxProd);
        }
        return maxProd;
    }
};
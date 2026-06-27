class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;  // Edge case: single or empty element
        
        int i = n - 2;
        
        // Step 1: Find the largest index i such that nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }
        
        // Step 2: If such i exists, find the smallest nums[j] > nums[i] from right
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        // Step 3: Reverse the subarray from i+1 to end
        reverse(nums.begin() + i + 1, nums.end());
        
        // No return statement needed because function returns void
        // We modified nums in-place
    }
};
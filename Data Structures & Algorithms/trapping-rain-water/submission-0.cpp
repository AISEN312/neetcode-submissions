class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0; // Water cannot be trapped

        int left = 0;
        int right = n - 1;
        int left_max = 0;
        int right_max = 0;
        int total_water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                // Left side is the bottleneck
                if (height[left] >= left_max) {
                    left_max = height[left]; // Update local max boundary
                } else {
                    total_water += left_max - height[left]; // Trap water
                }
                left++;
            } else {
                // Right side is the bottleneck
                if (height[right] >= right_max) {
                    right_max = height[right]; // Update local max boundary
                } else {
                    total_water += right_max - height[right]; // Trap water
                }
                right--;
            }
        }

        return total_water;
    }
};

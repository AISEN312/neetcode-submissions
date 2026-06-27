class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            int width = right - left;
            int current_height = min(height[left], height[right]);
            
            // Area calculate karke update karo
            int current_water = width * current_height;
            max_water = max(max_water, current_water);

            // Jis side ki height choti hai, us pointer ko move karo
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};

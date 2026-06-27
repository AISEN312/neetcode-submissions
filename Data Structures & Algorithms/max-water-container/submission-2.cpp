#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        for(int i = 0;i<heights.size();++i){
            for(int j = i+1;j<heights.size();++j){
                int area = min(heights[i],heights[j])*(j-i);
                res = max(res,area);
            }
        }
        return res;
    }
};

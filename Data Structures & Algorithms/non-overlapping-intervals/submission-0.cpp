class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int removals = 0;
        int prev_end = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= prev_end) {
                prev_end = intervals[i][1];
            } else {
                ++removals;
            }
        }
        return removals;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        // Transform s into T with separators so we handle even/odd uniformly
        string T = "^";
        for (char c : s) { T.push_back('#'); T.push_back(c); }
        T += "#$";

        int n = (int)T.size();
        vector<int> P(n, 0);
        int C = 0, R = 0;          // current center and right boundary
        int maxLen = 0, centerIdx = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirr = 2 * C - i;
            if (i < R) P[i] = min(R - i, P[mirr]);
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) ++P[i];
            if (i + P[i] > R) { C = i; R = i + P[i]; }
            if (P[i] > maxLen) { maxLen = P[i]; centerIdx = i; }
        }

        int start = (centerIdx - 1 - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};

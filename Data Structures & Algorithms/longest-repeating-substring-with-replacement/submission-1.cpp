#include <vector>
#include <string>
#include <algorithm> // For std::max
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0; // Initialize the result variable
        for (int i = 0; i < s.size(); ++i) { // Outer loop for starting index i
            vector<int> count(26, 0); // Reset count for each new starting index
            int maxf = 0; // Reset max frequency
            for (int j = i; j < s.size(); ++j) { // Inner loop extends the substring
                count[s[j] - 'A']++;
                maxf = max(maxf, count[s[j] - 'A']); // Update max frequency
                int window_size = j - i + 1;
                if (window_size - maxf <= k) { // Check if window is valid
                    res = max(res, window_size); // Update result if valid
                }
            }
        }
        return res; // Correctly placed return statement
    }
};

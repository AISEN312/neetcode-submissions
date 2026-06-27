#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> required(128, 0);
        int requiredCount = 0;
        for (char c : t) {
            if (required[c] == 0) {
                requiredCount++;
            }
            required[c]++;
        }
        
        vector<int> window(128, 0);
        int formed = 0;
        int left = 0;
        int min_length = INT_MAX;
        int start = 0;
        
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            
            if (required[c] > 0 && window[c] == required[c]) {
                formed++;
            }
            
            while (formed == requiredCount && left <= right) {
                if (right - left + 1 < min_length) {
                    min_length = right - left + 1;
                    start = left;
                }
                
                char left_char = s[left];
                window[left_char]--;
                if (required[left_char] > 0 && window[left_char] < required[left_char]) {
                    formed--;
                }
                left++;
            }
        }
        
        return min_length == INT_MAX ? "" : s.substr(start, min_length);
    }
};
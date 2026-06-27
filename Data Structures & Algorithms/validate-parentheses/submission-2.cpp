#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracket_map = {{')', '('}, {']', '['}, {'}', '{'}};
        
        for (char c : s) {
            if (bracket_map.count(c)) {
                if (st.empty() || st.top() != bracket_map[c]) 
                    return false;
                st.pop();
            } else {
                st.push(c);
            }
        }
        
        return st.empty();
    }
};
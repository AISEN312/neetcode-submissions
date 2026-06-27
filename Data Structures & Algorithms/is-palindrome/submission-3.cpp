#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string filtered;
        for(char c : s){
          if  (isalnum((unsigned char)c)) {
                filtered += tolower((unsigned char)c);
            ;

            }
        
    }
    string reversed = filtered;
    reverse(reversed.begin(),reversed.end());
    return filtered == reversed;}
};

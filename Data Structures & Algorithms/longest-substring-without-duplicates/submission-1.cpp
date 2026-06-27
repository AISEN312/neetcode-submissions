class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>charMap;
        int left = 0,maxLen = 0;
        for(int right = 0;right<s.size();++right){
            char current = s[right];
            if(charMap.find(current)!=charMap.end()&&charMap[current]>=left){
                left = charMap[current]+1;
            }
            charMap[current] = right;
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
        
    }
};

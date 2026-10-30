class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> count; 
        int maxLen = 0;
        int rt = 0; 
        int lt = 0;
        while (rt < s.length()) {  
            while (count.find(s[rt]) != count.end()) { 
                count.erase(s[lt]);
                lt++; 
            }
            count.insert({s[rt], 1});
            rt++;
            maxLen = max(rt - lt, maxLen);
        }  
        return maxLen;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> window; 
        int lt = 0; 
        int maxLen = 0;
        
        for (int rt = 0; rt < s.length(); rt++) { 
            while (window.find(s[rt]) != window.end()) { 
                window.erase(s[lt]); 
                lt++;
            }
            window.insert(s[rt]); 
            maxLen = max(maxLen, rt - lt + 1); 
        }    
        return maxLen; 
    }
};
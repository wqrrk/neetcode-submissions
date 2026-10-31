class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count; 
        int lt = 0; 
        int longest = 0; 
        int maxF = 0;
        for (int rt = 0; rt < s.length(); rt++) { 
            count[s[rt]]++;
            maxF = max(maxF, count[s[rt]]);
            
            while ((rt - lt + 1) - maxF > k) { 
                count[s[lt]]--; 
                lt++;
            }
            longest = max(rt - lt + 1, longest);
        }
        return longest; 
    }
};
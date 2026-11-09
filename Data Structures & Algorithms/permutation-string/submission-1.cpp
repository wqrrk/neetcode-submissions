
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) { 
            return false;
        }
        
        unordered_map<char,int> count; 

        for (int i = 0; i < s1.length(); i++) { 
            count[s1[i]]++;
        }
        int need = count.size();
        for (int i = 0; i < s2.length(); i++) { 
            unordered_map<char,int> window;
            int have = 0;
            for (int j = i; j < s2.length(); j++) { 
                window[s2[j]]++; 
                
                if (window[s2[j]] > count[s2[j]]) { 
                    break; 
                } 
                if (window[s2[j]] == count [s2[j]]) { 
                    have++;
                }
                if (have == need) { 
                    return true; 
                }
        
            }
        }
        return false;
    }
};
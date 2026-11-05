class Solution {
private: 
    bool isPalindrome(const string& s, int lt, int rt) {  
        while (lt < rt) { 
            if (s[lt] != s[rt]) { 
                return false;
            }
            lt++;
            rt--;
        }
        return true; 
    }

public:
    bool validPalindrome(string s) {
        int lt = 0; 
        int rt = s.length() - 1;

        while (lt <= rt) { 
            if (s[lt] != s[rt]) { 
                return isPalindrome(s,lt + 1, rt) || isPalindrome(s, lt, rt - 1); 
            }
            lt++;
            rt--;
        } 
        return true;       
    }
};
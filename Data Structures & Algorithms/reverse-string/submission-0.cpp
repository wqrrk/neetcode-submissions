class Solution {
public:
    void reverseString(vector<char>& s) {
        int lt = 0; 
        int rt = s.size() - 1; 

        while (lt <= rt) { 
            int sw = s[lt]; 
            s[lt] = s[rt]; 
            s[rt] = sw;
            lt++; 
            rt--; 
        }
    }
};
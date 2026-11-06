class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p = 0; 
        string res = "";

        while ((p < word1.length()) && (p < word2.length())) { 
            res += word1[p]; 
            res += word2[p]; 
            p++; 
        }

            res += word1.substr(p, word1.length()); 

            res += word2.substr(p, word2.length());

        return res;
    }
};
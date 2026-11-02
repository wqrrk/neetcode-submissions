class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window; 
        unordered_map<char,int> countT; 

        for (int i = 0; i < t.length(); i++) { 
            countT[t[i]]++;
        }

        int resLen = INT_MAX; 
        pair<int,int> res = {-1,-1}; 
        int lt = 0; 

        int have = 0; 
        int need = countT.size(); 

        for (int rt = 0; rt < s.length(); rt++) { 
            window[s[rt]]++; 

            if ((countT.find(s[rt]) != countT.end()) && (window[s[rt]] == countT[s[rt]])) { 
                have++; 
            }

            while (have == need) { 
                if (rt - lt + 1 < resLen) { 
                    resLen = rt - lt + 1;
                    res = {lt,rt};
                }

                window[s[lt]]--; 

                if ((countT.find(s[lt]) != countT.end()) && (window[s[lt]] < countT[s[lt]])) { 
                    have--; 
                }
                lt++; 
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen); 
    }
}; 
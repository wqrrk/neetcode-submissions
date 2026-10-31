class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window;
        unordered_map<char,int> countT;  
        
        for (int i = 0; i < t.length(); i++) {
            countT[t[i]]++; 
        }

        int have = 0; 
        int need = countT.size();

        int lt = 0; 
        pair<int,int> res = {-1,-1}; 
        int resLen = INT_MAX; 
        for (int rt = 0; rt < s.length(); rt++) { 
            window[s[rt]]++; 

            if ((countT.find(s[rt]) != countT.end()) && (window[s[rt]] == countT[s[rt]])) { 
                have++;
            }

            while (have == need) { 
                //update result
                if ((rt - lt + 1) < resLen) { 
                    res = {lt,rt};
                    resLen = rt - lt + 1;
                }

                //remove a char from window
                window[s[lt]]--;

                //if we took out a char that we have in the T string
                if ((countT.find(s[lt]) != countT.end()) && (window[s[lt]] < countT[s[lt]])) { 
                     have--;
                }
                lt++; 
            }
                     
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen); 
    }
}; 
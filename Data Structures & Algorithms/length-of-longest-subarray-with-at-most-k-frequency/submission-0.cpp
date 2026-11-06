class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> window; 
        int maxSize = 0;
        int lt = 0;
        for (int rt = 0; rt < nums.size(); rt++) { 
            window[nums[rt]]++; 
            while (window[nums[rt]] > k) { 
                window[nums[lt]]--;  
                lt++;
            }
            if ((rt - lt + 1) > maxSize) {
                maxSize = rt - lt + 1;
            }
        }
        return maxSize;
    }
};
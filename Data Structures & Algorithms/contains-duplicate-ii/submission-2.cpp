class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> window; 
        int lt = 0;

        for (int rt = 0; rt < nums.size(); rt++) { 
            if (rt - lt > k) { 
                window.erase(nums[lt]); 
                lt++;
            }
            if (window.find(nums[rt]) != window.end()) { 
                return true;
            }

            window.insert(nums[rt]); 
        }
        return false;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> count; 
        vector<int> res; 
        
        for (int num : nums) { 
            count[num]++;
        }
        for (const auto& [key, value] : count) { 
            if (value > (nums.size() / 3)) { 
                res.push_back(key);
            }
        }
        return res;
    }
};
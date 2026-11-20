class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) { 
            return -1;
        }

        int lt = 0;
        int rt = nums.size() - 1;
        
        while(lt <= rt) { 
            int mid = lt + (rt - lt) / 2; 
            if (nums[mid] == target) { 
                return mid; 
            } else if (nums[mid] < target) { 
                lt = mid + 1; 
            } else { 
                rt = mid - 1;
            }
        }
        return -1;
    }
};
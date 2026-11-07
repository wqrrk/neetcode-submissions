class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lt = 0; 
        int rt = nums.size() - 1;
        while (lt <= rt) { 
            int mid = lt + (rt-lt) / 2;
            int midNum = nums[mid];
            if (midNum < target) { 
                lt = mid + 1;
            } else if (midNum > target) { 
                rt = mid - 1;

            } else { 
                return mid;
            }
        }
        return lt;
    }
};
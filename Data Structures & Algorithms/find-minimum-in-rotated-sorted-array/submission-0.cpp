class Solution {
public:
    int findMin(vector<int> &nums) {
        int lt = 0; 
        int rt = nums.size() - 1; 
        while (lt < rt) { 
            int mid = lt + (rt - lt) / 2;
            if (nums[mid] > nums[nums.size() - 1]) { 
                lt = mid + 1;
            } else { 
                rt = mid; 
            }
        }
        return nums[lt]; 
    }
};
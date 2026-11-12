class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int lt, int rt) { 
        while (lt <= rt) { 
            int mid = lt + (rt - lt) / 2;
            if (nums[mid] > target) { 
                rt = mid - 1;
            } else if (nums[mid] < target) { 
                lt = mid + 1;
            } else { 
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
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
        //now we stored the cut in the lt 
        // let's find the target now

        //check if the array is not actually rotated
        if (lt == 0) { 
            return binarySearch(nums,target,0,nums.size() - 1);
        }
        
        //however, if it is, check one of the halfs
        if  (nums[0] <= target) { 
            return binarySearch(nums, target, 0, lt - 1); 
        } else { 
            return binarySearch(nums, target, lt, nums.size() - 1);
        }
    }
};
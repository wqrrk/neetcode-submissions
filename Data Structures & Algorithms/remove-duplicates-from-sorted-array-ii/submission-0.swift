class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        guard nums.count > 2 else {
            return nums.count
        }
        
        var lt = 2
        var rt = 2
        
        while rt != nums.count {
            if nums[rt] != nums[lt - 2] {
                nums[lt] = nums[rt]
                lt += 1
            }
            rt += 1
        }
        return lt
    }
}
class Solution {
    func removeDuplicates(_ nums: inout [Int]) -> Int {
        guard nums.count > 0 else {
            return 0
        }
        var lt = 1
        var rt = 1
        
        while rt < nums.count {
            if nums[rt] != nums[rt - 1] {
                nums[lt] = nums[rt]
                lt += 1
            }
            rt += 1
        }
        return lt
    }
}
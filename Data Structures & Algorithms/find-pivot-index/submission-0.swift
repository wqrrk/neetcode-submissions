class Solution {
    func pivotIndex(_ nums: [Int]) -> Int {
        var prefix = Array(repeating: 0, count: nums.count + 1)
        var suffix = Array(repeating: 0, count: nums.count + 1)
        
        for i in 0..<nums.count {
            prefix[i + 1] = prefix[i] + nums[i]
        }
        
        for i in (0..<nums.count).reversed() {
            suffix[i] = suffix[i + 1] + nums[i]
        }
        
        for i in nums.indices {
            if prefix[i] == suffix[i + 1] {
                return i
            }
        }
        return -1
    }
}
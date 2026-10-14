class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var prevNums: Dictionary<Int,Int> = [:]
        for i in nums.indices {
            if let compliment = prevNums[target - nums[i]] {
                return [compliment, i]
            } else {
                prevNums[nums[i]] = i
            }
        }
        return []
    }
}
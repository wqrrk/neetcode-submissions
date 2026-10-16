class Solution {
    func getConcatenation(_ nums: [Int]) -> [Int] {
        var ans = nums
        for i in nums.indices {
            ans.append(nums[i])
        }
        return ans
    }
}
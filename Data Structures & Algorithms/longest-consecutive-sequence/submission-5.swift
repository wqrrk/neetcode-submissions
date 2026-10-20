class Solution {
    func longestConsecutive(_ nums: [Int]) -> Int {
        let numsSet = Set(nums)
        var maxLen = 0
        for num in numsSet {
            if !numsSet.contains(num - 1) {
                var current = num
                var currentLen = 1
                
                while numsSet.contains(current + 1) {
                    currentLen += 1
                    current += 1
                }
                maxLen = max(currentLen, maxLen)
            }
        }
        return maxLen
    }
}
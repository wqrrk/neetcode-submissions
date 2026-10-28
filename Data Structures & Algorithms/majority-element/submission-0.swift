class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var freq = Dictionary<Int, Int>()
        for num in nums {
            freq[num, default: 0] += 1
        }
        return freq.max(by: {$0.value < $1.value })!.key
    }
}
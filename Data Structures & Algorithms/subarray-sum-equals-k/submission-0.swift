class Solution {
    func subarraySum(_ nums: [Int], _ k: Int) -> Int {
        var prefixSums: Dictionary<Int, Int> = [0 : 1]
        var res = 0
        var currSum = 0
        for num in nums {
            currSum += num
            let diff = currSum - k
            res += prefixSums[diff, default: 0]
            prefixSums[currSum, default: 0] += 1
        }
        return res
    }
}
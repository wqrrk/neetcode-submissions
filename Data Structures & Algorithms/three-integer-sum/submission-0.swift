class Solution {
    func threeSum(_ nums: [Int]) -> [[Int]] {
        var result: Set<[Int]> = []
        let sortedNums = nums.sorted()
        for i in 0..<nums.count - 2 {
            var lt = i + 1
            var rt = nums.count - 1
            while lt < rt {
                let currentSum = sortedNums[i] + sortedNums[lt] + sortedNums[rt]
                if currentSum < 0 {
                    lt += 1
                } else if currentSum > 0 {
                    rt -= 1
                } else {
                    result.insert([sortedNums[i],sortedNums[lt],sortedNums[rt]])
                    lt += 1
                }
            }
        }
        return Array(result)
    }
}
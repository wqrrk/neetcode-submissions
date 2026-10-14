class Solution {
    func topKFrequent(_ nums: [Int], _ k: Int) -> [Int] {
        var freq: Dictionary<Int, Int> = [:]
        for num in nums {
            freq[num, default: 0] += 1
        }
        let sortedFreq = freq.sorted {$0.value > $1.value}
        let result = sortedFreq.prefix(k)
            .map { $0.key }
        return result
    }
}
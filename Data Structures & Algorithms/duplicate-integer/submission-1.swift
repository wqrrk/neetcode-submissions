class Solution {
    func hasDuplicate(_ nums: [Int]) -> Bool {
        var elements: Set<Int> = Set()
        for num in nums {
            if elements.contains(num) {
                return true
            } else {
                elements.insert(num)
            }
        }
        return false
    }
}
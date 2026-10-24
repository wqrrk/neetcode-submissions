class Solution {
    func twoSum(_ numbers: [Int], _ target: Int) -> [Int] {
        var lt = 0
        var rt = numbers.count - 1
        
        while lt < rt {
            var currentSum = numbers[lt] + numbers[rt]
            if currentSum > target {
                rt -= 1
            } else if currentSum < target {
                lt += 1
            } else {
                return [lt + 1,rt + 1]
            }
        }
        return []
    }
}
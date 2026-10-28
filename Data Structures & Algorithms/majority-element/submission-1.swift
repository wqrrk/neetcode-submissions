class Solution {
    func majorityElement(_ nums: [Int]) -> Int {
        var res = 0 
        var count = 0 

        for num in nums {
            if count == 0 { 
                res = num
            }
            count += num == res ? 1 : -1
        }
        return res
    }
}
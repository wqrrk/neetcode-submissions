class Solution {
    func trap(_ height: [Int]) -> Int {
        
        guard !height.isEmpty else { return 0 }
        
        var lt = 0
        var leftMax = height[lt]
        var rt = height.count - 1
        var rightMax = height[rt]
        var totalWater = 0
        
        
        while lt < rt {
            if leftMax < rightMax {
                lt += 1
                leftMax = max(leftMax, height[lt])
                totalWater += leftMax - height[lt]
            } else {
                rt -= 1
                rightMax = max(rightMax, height[rt])
                totalWater += rightMax - height[rt]
            }
        }
        
        return totalWater
    }
}
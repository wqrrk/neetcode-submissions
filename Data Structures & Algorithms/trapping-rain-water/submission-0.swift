class Solution {
    func trap(_ height: [Int]) -> Int {
        var res: Int = 0
        var leftMax = Array(repeating: 0, count: height.count)
        var rightMax = Array(repeating: 0, count: height.count)
        

        guard !height.isEmpty else { return 0 }

        leftMax[0] = height[0] // the first element of the leftMax should be the first elem of height
        rightMax[height.count - 1] = height[height.count - 1] // mirror this for the right element 

        for i in 1..<height.count {
            leftMax[i] = max(leftMax[i - 1], height[i])
        }
        for i in (0..<height.count - 1).reversed() {
            rightMax[i] = max(rightMax[i + 1], height[i])
        }
        
        for i in height.indices {
            res += (min(leftMax[i], rightMax[i]) - height[i]) > 0 ? (min(leftMax[i], rightMax[i]) - height[i]) : 0
        }
        return res
    }
}
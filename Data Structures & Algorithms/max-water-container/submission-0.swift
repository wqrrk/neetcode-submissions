class Solution {
    func maxArea(_ height: [Int]) -> Int {
        var lt = 0
        var rt = height.count - 1
        var maxArea = 0
        
        while lt < rt {
            let area = (rt - lt) * min(height[lt], height[rt])
            if area > maxArea {
                maxArea = area
            }
            if height[rt] < height[lt] {
                rt-=1
            } else {
                lt += 1
            }
        }
        return maxArea
    }
}
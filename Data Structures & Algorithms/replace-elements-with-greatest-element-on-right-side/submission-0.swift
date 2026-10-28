class Solution {
    func replaceElements(_ arr: [Int]) -> [Int] {
        var rightMax = Array(repeating: 0, count: arr.count)
        rightMax[rightMax.count - 1] = -1
        for i in (0..<arr.count - 1).reversed() {
            rightMax[i] = max(rightMax[i + 1], arr[i + 1])
        }
        
        return rightMax
    }
}
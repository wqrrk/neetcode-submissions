class Solution {
    func maxDepth(_ root: TreeNode?) -> Int {
        guard let node = root else {
            return 0
        }
        
        let leftMax = maxDepth(node.left)
        let rightMax = maxDepth(node.right)
        
        return max(leftMax, rightMax) + 1
        
    }
}
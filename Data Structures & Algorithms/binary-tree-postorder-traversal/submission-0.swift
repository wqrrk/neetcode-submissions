/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     var val: Int
 *     var left: TreeNode?
 *     var right: TreeNode?
 *     init(_ val: Int) {
 *         self.val = val
 *         self.left = nil
 *         self.right = nil
 *     }
 * }
 */

class Solution {
    func traverse(_ n: TreeNode?, result: inout [Int]) { 
        guard let node = n else { 
            return 
        }
        traverse(node.left,result: &result)
        traverse(node.right, result: &result)
        result.append(node.val)
    }


    func postorderTraversal(_ root: TreeNode?) -> [Int] {
        var result: [Int] = []
        traverse(root, result: &result)
        return result
    }
}

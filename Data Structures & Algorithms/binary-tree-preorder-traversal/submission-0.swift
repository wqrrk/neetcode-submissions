class Solution {

    func traverse(_ n: TreeNode?, result: inout [Int]) {
        guard let node = n else {
            return
        }
        result.append(node.val)
        traverse(node.left, result: &result)
        traverse(node.right, result: &result)
    }

    func preorderTraversal(_ root: TreeNode?) -> [Int] {
        var result: Array<Int> = []
        traverse(root, result: &result)
        return result
    }
}
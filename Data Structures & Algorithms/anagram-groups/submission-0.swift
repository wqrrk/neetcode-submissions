class Solution {
    func groupAnagrams(_ strs: [String]) -> [[String]] {
        var groups: [[Int]: [String]] = [:]
        for str in strs {
            var currentStrKey = Array<Int>(repeating: 0, count: 26)
            for c in str {
                currentStrKey[Int(c.asciiValue!) - 97] += 1
            }
            groups[currentStrKey, default: []].append(str)
        }
        return Array(groups.values)
    }
}
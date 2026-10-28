class Solution {
    func longestCommonPrefix(_ strs: [String]) -> String {
        let charsArr = strs.map { Array($0) }
        let firstStr = Array<Character>(strs[0])
        var longestPref = ""
        for i in 0..<firstStr.count {
            for word in charsArr {
                guard i < word.count else {
                    return longestPref
                }
                if firstStr[i] != word[i] {
                    return longestPref
                }
            }
            longestPref += String(firstStr[i])
            
        }
        return longestPref
    }
}
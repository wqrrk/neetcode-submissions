class Solution {
    func isValid(_ s: String) -> Bool {
        let parentheses: Dictionary<Character,Character> = ["}":"{", ")":"(", "]":"["]
        var seq: [Character] = []
        for ch in s {
            if let opening = parentheses[ch] {
                if seq.last == opening {
                    seq.removeLast()
                } else {
                    return false
                }
            } else {
                seq.append(ch)
            }
        }
        return seq.isEmpty
    }
}
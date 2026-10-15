class Solution {
    func encode(_ strs: [String]) -> String {
        var encodedString: String = ""
        for str in strs {
            encodedString += "\(str.count)#\(str)"
        }
        return encodedString
    }

    func decode(_ str: String) -> [String] {
        var decodedString: [String] = []
        let chars: Array<Character> = Array(str)
        var p = 0
        var readNum = 0
        while p < chars.count {
            if let number = chars[p].wholeNumberValue {
                readNum = readNum * 10 + number
                p += 1
            } else if chars[p] == "#" {
                decodedString.append(String(chars[p + 1 ..< p + readNum + 1]))
                p += (readNum + 1)
                readNum = 0
            }
        }
        return decodedString
    }
}
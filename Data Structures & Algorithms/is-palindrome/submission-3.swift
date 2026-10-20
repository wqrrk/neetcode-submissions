class Solution {
    func isPalindrome(_ s: String) -> Bool {
        var chars = Array(s.lowercased())
        // print(chars)
        var lt = 0
        var rt = s.count - 1
        while lt < rt {
            //check if there is a whitespace
            if !chars[lt].isLetter && !chars[lt].isNumber {
                //print(chars[lt])
                lt += 1
                continue
            } else if !chars[rt].isLetter && !chars[rt].isNumber {
                //print(chars[rt])
                rt -= 1
                continue
            }
            
            if chars[lt] != chars[rt] {
                return false
            }
            
            lt += 1
            rt -= 1
        }
        return true
    }
}
class Solution {
    func isAnagram(_ s: String, _ t: String) -> Bool {
        var freq: Dictionary<Character, Int> = [:]

        for ch in s { 
            freq[ch] = freq[ch,default: 0] + 1
        }
        
        for ch in t { 
            if let currFreq = freq[ch], currFreq == 1{ 
                freq[ch] = nil
            } else if let currFreq = freq[ch] { 
                freq[ch] = currFreq - 1
            } else { 
                return false
            }
        }
        return freq.isEmpty
    }
}

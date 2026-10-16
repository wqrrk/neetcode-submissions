class Solution {
    func productExceptSelf(_ nums: [Int]) -> [Int] {
    var pref: Array<Int> = Array(repeating: 1, count: nums.count)
    var suff: Array<Int> = Array(repeating: 1, count: nums.count)
    for i in (1..<nums.count) {
        pref[i] = (nums[i - 1] * pref[i - 1])
    }
    for i in (0..<nums.count - 1).reversed() {
        suff[i] = suff[i + 1] * nums[i + 1]
    }
    return zip(pref,suff).map(*)
}
}
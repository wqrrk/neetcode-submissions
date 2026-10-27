func isValid(s string) bool {
	dict := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}
	stack := []rune{}
	
	for _, v := range s {
		value, ok := dict[v] //if we got an opening bracket,then out current one is closing
		if ok {   
			if len(stack) == 0 { //found a closing bracket but the stack is empty(
				return false
			}           // found an closing bracket
			if stack[len(stack)-1] == value {
                
				stack = stack[:len(stack)-1]
			} else { 
				return false
			}
		} else {
			stack = append(stack, v)
		}
	}
	return len(stack) == 0
}
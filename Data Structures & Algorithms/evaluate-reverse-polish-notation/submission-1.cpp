class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack; 
        for (int i = 0; i < tokens.size(); i++) { 
            if (tokens[i] == "+") {
                int op2 = stack.top(); 
                stack.pop();
                int op1 = stack.top();
                stack.pop();
                stack.push(op1 + op2);
            } else if (tokens[i] == "-") {
                int op2 = stack.top();
                stack.pop();
                int op1 = stack.top();
                stack.pop(); 
                stack.push(op1 - op2);
            } else if (tokens[i] == "*") {
                int op2 = stack.top();
                stack.pop(); 
                int op1 = stack.top();
                stack.pop();
                stack.push(op1 * op2);
            } else if (tokens[i] == "/") {
                int op2 = stack.top();
                stack.pop();
                int op1 = stack.top();
                stack.pop();
                stack.push(op1 / op2);
                
            } else {
                stack.push(stoi(tokens[i]));
            }
        }
        return stack.top();
    }
};


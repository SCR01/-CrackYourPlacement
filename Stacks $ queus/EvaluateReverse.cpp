class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        for (const string& token : tokens) {
            if (isdigit(token.back())) {
                stack.push(stoi(token));
            } else {
                int val2 = stack.top();
                stack.pop();
                int val1 = stack.top();
                stack.pop();
                int result;
                switch (token[0]) {
                    case '*':
                        result = val1 * val2;
                        break;
                    case '+':
                        result = val1 + val2;
                        break;
                    case '-':
                        result = val1 - val2;
                        break;
                    case '/':
                        result = val1 / val2;
                        break;
                }
                stack.push(result);
            }
        }
        return stack.top();
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        std::set<string> operators {"+", "-", "*", "/"};

        for (auto token: tokens) {
            if (!operators.contains(token)) {
                stk.push(stoi(token));
            } else {
                int op2 = stk.top();
                stk.pop();
                int op1 = stk.top();
                stk.pop();

                if (token == "+") {
                    stk.push(op1 + op2);
                } else if (token == "-") {
                    stk.push(op1 - op2);
                } else if (token == "*") {
                    stk.push(op1 * op2);
                } else if (token == "/") {
                    stk.push(op1 / op2);
                }
            }        
        }        
        return stk.top();
    }
};

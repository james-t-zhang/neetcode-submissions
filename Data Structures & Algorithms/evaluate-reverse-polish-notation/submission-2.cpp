class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        stack<int> st;

        string op;
        int x;
        int y;

        for (string t : tokens) {
            if (t == "+" ||
                t == "-" ||
                t == "*" ||
                t == "/") {
                    op = t;

                    // Pop 2 numbers from the stack
                    y = st.top(); // First number is SECOND OPERAND
                    st.pop();

                    x = st.top(); // Second number is FIRST OPERAND
                    st.pop();

                    // Operation
                    // Addition
                    if (op == "+") {
                        x += y;
                    } 
                    
                    // Subtraction
                    else if (op == "-") {
                        x -= y;
                    } 
                    
                    // Multiplication
                    else if (op == "*") {
                        x *= y;
                    } 
                    
                    // Division
                    else {
                        x /= y;
                    }

                    // Place the resulting number in the stack
                    st.push(x);
                }

            else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};

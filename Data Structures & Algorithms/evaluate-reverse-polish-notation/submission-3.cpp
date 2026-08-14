class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Edge case
        if (tokens.size() == 1) {
            return stoi(tokens[0]);
        }

        // The stack for the stack problem..
        stack<int> st;

        // Variables
        string op; // operator
        int x; // first operand (X - Y) (X / Y) (X + Y) (X * Y)
        int y; // second operand (X - Y) (X / Y) (X + Y) (X * Y)

        // Loop through the vector to process all strings
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

            // If not opertor, push number into stack
            else {
                st.push(stoi(t));
            }
        }

        // Stack should have one number left
        return st.top();
    }
};

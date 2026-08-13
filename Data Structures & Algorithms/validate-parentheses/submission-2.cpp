class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<char> st;

        for (const char& c : s) {
            if (c == '(' ||
                c == '[' ||
                c == '{') {
                st.push(c);
            }
            else if (st.empty()) {
                return false;
            }
            else {
                if ((st.top() == '(' && c == ')') ||
                    (st.top() == '[' && c == ']') ||
                    (st.top() == '{' && c == '}')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};

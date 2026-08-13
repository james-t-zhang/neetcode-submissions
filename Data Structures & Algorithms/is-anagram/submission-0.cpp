class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> m1;

        // string s loop
        for (char c : s) {
            // add char
            if (m1.find(c) == m1.end()) {
                m1[c] = 1;
            }
            else {
                m1[c]++;
            }
        }

        // string t loop
        for (char c : t) {
            auto it = m1.find(c);
            if (it == m1.end()) {
                return false;
            }
            else {
                if (it->second == 0) {
                    return false;
                }
                else {
                    m1[c]--;
                    if (m1[c] == 0) {
                        m1.erase(c);
                    }
                }
            }
        }

        if (m1.empty()){
            return true;
        }
        return false;
    }
};

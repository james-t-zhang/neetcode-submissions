class Solution {
public:

    string encode(vector<string>& strs) {
        // return string
        string ret = "";

        // Loop over vector and concatenate over ret
        for (const string& str : strs) {
            ret += str;
            ret += "-|-";
        }

        return ret;
    }

    vector<string> decode(string s) {
        int count = 0;
        vector<string> ans;
        string cur_s = "";
        string maybe_not_delimiter = "";

        // Loop through s
        for (char c : s) {
            if (c == '-' && count == 0) {
                // Add char to maybe_not_delimiter
                maybe_not_delimiter += '-';
                
                // Increment count
                count++;
            }
            else if (c == '-' && count == 2) {
                // Add string to vector
                ans.push_back(cur_s);

                // Reset cur_s
                cur_s = "";

                // Reset maybe_not_delimiter
                maybe_not_delimiter = "";

                // Reset count
                count = 0;
            }
            else if (c == '|' && count == 1) {
                // Add char to maybe_not_delimiter
                maybe_not_delimiter += '|';

                // Increment count
                count++;
            }
            else {
                if (count >= 1) {
                    // Add char from maybe_not_delimiter
                    cur_s += maybe_not_delimiter;

                    // Reset maybe_not_delimiter
                    maybe_not_delimiter = "";

                    // Reset count
                    count = 0;
                }
                cur_s += c;
            }
        }

        return ans;
    }
};

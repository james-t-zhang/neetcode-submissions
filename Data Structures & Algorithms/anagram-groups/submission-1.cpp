class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;

        // dictionary
        // key ----- 26 integers separated by a delimiter '-'
        // value --- vector of anagram-related words
        unordered_map<string, vector<string>> dictionary; 

        // int iterator for dictionary
        int i = 0;

        // iterate through strs
        for (string str : strs) {
            // Create signature of "str"
            string strSig = createSignature(str);

            // Adds key-value pair if absent
            // Adds to existing key-value pair
            dictionary[strSig].push_back(str); // push_back() str into vector at strSig
        }

        // Iterate through dictionary to retrieve vectors
        for (const auto& pair : dictionary) {
            answer.push_back(pair.second); // pair.second is the vector of words in each entry
        }

        return answer;
    }

    string createSignature(string str) {
        string final_str = "";
        int count_of_letters[26] = {0};

        // iterate through each letter
        for (char c : str) {
            // 'a' has ascii value of 97; 'a' index is 0; subtract "c" by 97
            count_of_letters[static_cast<int>(c) - 97]++; // increment
        }

        // iterate through "count_of_letters" and create finalized string
        for (int count : count_of_letters) {
            final_str += to_string(count); // Add string format of count
            final_str += '-'; // Add delimiter
        }

        return final_str;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> outputM;
        std::unordered_map<string, vector<string>> sigKey;

        // allocate words into correct groups -> sigKey
        for (std::string word : strs) {
            // store original word
            std::string oriWord = word;

            // sort string
            std::sort(word.begin(), word.end());

            // check if inside map
            auto it = sigKey.find(word);

            // add word to existing vector
            if (it != sigKey.end()) {
                it->second.push_back(oriWord);
            }

            // add new vector w/ signature
            else {
                vector<string> v;
                v.push_back(oriWord);
                sigKey.insert({word, v});
            }
        }

        // retrieve correct groups from sigKey -> outputM
        for (auto& item : sigKey) {
            outputM.push_back(item.second);
        }

        return outputM;
    }
};

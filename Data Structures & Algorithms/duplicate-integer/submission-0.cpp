class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // create map
        std::unordered_map<int, int> m1;

        // run loop
        // store keys into map, value arbitrary
        for (int num : nums) {
            // Check if its in map already
            if (m1.find(num) == m1.end()) { // can't find it
                m1.insert({num, num});
            }

            else { // found
                return true;
            }
        }

        // return false if no early exit
        return false;
    }
};
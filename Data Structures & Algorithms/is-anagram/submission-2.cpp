class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> inventory;

        // add char into map
        for (char chars : s) {
            if (inventory.find(chars) != inventory.end()) {
                inventory[chars]++;
            }
            else {
                inventory[chars] = 1;
            }
        }

        // check is all chars are in map; decrement when found
        for (char chart : t) {
            if (inventory.find(chart) != inventory.end()) {
                inventory[chart]--;

                if (inventory[chart] == 0) {
                    inventory.erase(chart);
                }
            }
            else {
                return false;
            }
        }

        // make sure the map is empty
        if (inventory.empty()) {
            return true;
        }

        return false;
    }
};

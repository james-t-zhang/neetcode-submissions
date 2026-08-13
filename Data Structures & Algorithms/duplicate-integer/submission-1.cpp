class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> inventory;

        for (auto num : nums) {
            // check if num is in inventory
            if (inventory.find(num) != inventory.end()) {
                return true;
            }
            else {
                inventory[num] = true;
            }
        }

        return false;
    }
};
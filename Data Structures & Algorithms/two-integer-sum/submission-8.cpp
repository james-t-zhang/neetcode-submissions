class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> m1;

        std::unordered_map<int, int> map1;

        int i = 0;

        for (int num : nums) {
            // Add number
            map1.insert({target-num, i});

            // Retrieve end iterator or complement
            auto it = map1.find(num);

            // Check if there is a pair that matches
            if (it != map1.end() && it->second != i){
                m1.push_back(it->second);
                m1.push_back(i);
                return m1;
            }

            i++;
        }

        return m1;
    }
};

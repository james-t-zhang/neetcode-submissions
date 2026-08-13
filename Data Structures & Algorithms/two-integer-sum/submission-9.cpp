class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> desired;
        std::vector<int> answer;
        int i = 0;

        for (int num : nums) {
            if (desired.find(num) != desired.end()) { // check if num is a desired number
                answer.push_back(desired[num]); // Add smaller index (old)
                answer.push_back(i); // Add bigger index (current)
                return answer;
            }
            else {
                desired[target - num] = i; // add key-value pair
            }

            i++; // iterate
        }

        return answer;
    }
};

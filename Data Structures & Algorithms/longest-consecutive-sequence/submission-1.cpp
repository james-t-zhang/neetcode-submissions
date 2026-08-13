class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create hashmap 
        unordered_map<int, bool> s_nums;

        // Add to hashmap
        for (int num : nums) {
            s_nums[num] = true;
        }

        int cur_num;
        int consec_length = 0;
        int max_consec_length = 0;

        // Find Consecutives
        for (const auto& p : s_nums) {
            if (s_nums.find(p.first - 1) != s_nums.end()) {
                continue;
            }

            // If code reaches here, this is the first of its sequence
            cur_num = p.first;
            consec_length = 1;

            // Loop iterations of +1 until we find the end
            while (s_nums.find(cur_num + 1) != s_nums.end()) {
                consec_length++;
                cur_num++;
            }
            
            if (consec_length > max_consec_length) {
                max_consec_length = consec_length;
            }
        }

        return max_consec_length;
    }
};

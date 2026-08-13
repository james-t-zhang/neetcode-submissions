class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;

        int nums_size = nums.size();

        vector<int> left(nums_size, 1);

        vector<int> right(nums_size, 1);

        int left_counter = 1;

        int right_counter = 1;

        // Count left
        for (int i = 1; i < nums_size; i++) {
            left_counter *= nums[i - 1];
            left[i] = left_counter;
        }

        // Count right
        for (int i = nums_size - 2; i >= 0; i--) {
            right_counter *= nums[i + 1];
            right[i] = right_counter;
        }

        for (int i = 0; i < nums_size; i++) {
            ans.push_back(left[i] * right[i]);
        }

        return ans;
    }
};

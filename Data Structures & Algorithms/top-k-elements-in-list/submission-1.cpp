class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        // Frequency List
        // Integer -> Count
        unordered_map<int, int> freq_list;

        // Loop through nums
        for (int num : nums) {
            // Found in list, increment
            if (freq_list.find(num) != freq_list.end()) {
                freq_list[num]++;
            }

            // Not found in list, set to 1
            else {
                freq_list[num] = 1;
            }
        }

        // Reverse Frequency List
        // Count -> Vector_Bucket(Integer)
        int max_freq = nums.size() + 1;
        vector<vector<int>> freq_buckets(max_freq);

        // Loop through Frequency List
        for (const auto& x : freq_list) {
            freq_buckets[x.second].push_back(x.first);
        }

        // Find answer inside reverse frequency list by looping backwards
        for (int i = max_freq - 1; i >= 0; i--) {
            if (!freq_buckets[i].empty()) {
                while (!freq_buckets[i].empty()) {
                    ans.push_back(freq_buckets[i].back());
                    freq_buckets[i].pop_back();
                }

                if (ans.size() >= k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};

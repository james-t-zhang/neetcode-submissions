class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // push all nums into a hash map
        std::unordered_map<int, int> map1;
        for (int num : nums) {
            if (map1.find(num) == map1.end()) {
                map1[num] = 1;
            } else {
                map1[num] += 1;
            }
        }

        // use hash map to load up a bucket array (size n)
        std::vector <int> bucketArray[nums.size() + 1];
        for (auto& item : map1) {
            bucketArray[item.second].push_back(item.first);
        }

        // create a vector that accepts athe top k frequent elements
        // iterate backwards
        std::vector <int> output;
        for (int i = nums.size(); i > 0; i--) {
            if (!bucketArray[i].empty()) {
                for (int n : bucketArray[i]) {
                    output.push_back(n);

                    if (output.size() == k) {
                        return output;
                    }
                }
            }
        }

        return output;
    }
};

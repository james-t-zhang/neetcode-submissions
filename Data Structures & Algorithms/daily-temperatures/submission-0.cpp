class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Monotonic Decreasing Stack
        stack<pair<int, int>> st; // Stack to organize temperatures in decreasing values
        vector<int> ans(temperatures.size()); // Return vector

        // Loop through temperatures to add to stack
        for (int i; i < temperatures.size(); i++) {
            // We should start popping shit
            while (!st.empty() && st.top().first < temperatures[i]) {
                ans[st.top().second] = i - st.top().second; // Record the difference between indices

                st.pop(); // Get rid of temperature log
            }
        
            pair<int, int> p(temperatures[i], i); // FIRST: temperature, SECOND: index
            st.push(p);
        }

        // Stack can still hold pairs
        // Remaining pairs will have a ZERO as the entry, since no temperature within the array/vector onwards exceeded it
        while (!st.empty()) {
            ans[st.top().second] = 0; // Record ZERO (0) as entry for index

            st.pop(); // Remove pair from stack
        }

        return ans;
    }
};

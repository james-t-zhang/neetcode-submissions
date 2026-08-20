class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Go through position and speed arrays to calculate TTF (time-to-finish) the target distance
        // Add them into a stack from 0-th to i-th car.

        // Edge case
        if (position.size() == 1) {
            return 1;
        }

        // Variables
        vector<pair<int, double>> car_order; // Vector of all the cars to be sorted by positions
        double ttf; // Time-to-finish, "(target - position) / speed = ttf"
        stack<double> st_ttf; // Stack of ttf's, 0th car bottom, ith car top
        int num_fleets = 0; // number of fleets / groups
        double last_ttf = 0; // Last car's ttf


        // Put into vector of car sorted by position
        for (int i = 0; i < position.size(); i++) {
            // Calculate TTF
            ttf = (double)(target - position[i]) / speed[i];
            pair<int, double> p(position[i], ttf);

            // Push onto vector
            car_order.push_back(p);
        }

        // Sort vector
        sort(car_order.begin(), car_order.end());

        // Put into stack
        for (const auto& c : car_order) {
            st_ttf.push(c.second);
        }

        // .top() and .pop() all entries
        // Compare the current car with the last car

        // Iterate through stack
        while (!st_ttf.empty()) {
            if (st_ttf.top() > last_ttf) {
                num_fleets++;
                last_ttf = st_ttf.top();
            }

            // Iterate
            st_ttf.pop();
        }

        return num_fleets;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int, bool>> hori_map(9); // row, r

        vector<unordered_map<int, bool>> vert_map(9); // col, c

        // Left to Right, Top to Bottom
        vector<unordered_map<int, bool>> squa_map(9);

        char cell_num;

        for (int r = 0; r < 9; r++) { // row
            for (int c = 0; c < 9; c++) { // col
                // Set sudoku cell_num
                cell_num = board[r][c];

                // Continue if not "."
                if (cell_num != '.') {
                    // Horizontal Add
                    if (hori_map[r].find(cell_num) != hori_map[r].end()) {
                        return false;
                    }
                    // Add cell_num to hori_map[r]
                    hori_map[r][cell_num] = true;

                    // Vertical Add
                    if (vert_map[c].find(cell_num) != vert_map[c].end()) {
                        return false;
                    }
                    // Add cell_num to vert_map[c]
                    vert_map[c][cell_num] = true;

                    // Square Checks
                    if (r < 3) {
                        // Square 0
                        if (c < 3) {
                            if (squa_map[0].find(cell_num) != squa_map[0].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[0][cell_num] = true;
                        }
                        // Square 1
                        else if (c < 6) {
                            if (squa_map[1].find(cell_num) != squa_map[1].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[1][cell_num] = true;
                        }
                        // Square 2
                        else {
                            if (squa_map[2].find(cell_num) != squa_map[2].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[2][cell_num] = true;
                        }
                    }
                    else if (r < 6) {
                        // Square 3
                        if (c < 3) {
                            if (squa_map[3].find(cell_num) != squa_map[3].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[3][cell_num] = true;
                        }
                        // Square 4
                        else if (c < 6) {
                            if (squa_map[4].find(cell_num) != squa_map[4].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[4][cell_num] = true;
                        }
                        // Square 5
                        else {
                            if (squa_map[5].find(cell_num) != squa_map[5].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[5][cell_num] = true;
                        }
                    }
                    else {
                        // Square 6
                        if (c < 3) {
                            if (squa_map[6].find(cell_num) != squa_map[6].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[6][cell_num] = true;
                        }
                        // Square 7
                        else if (c < 6) {
                            if (squa_map[7].find(cell_num) != squa_map[7].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[7][cell_num] = true;
                        }
                        // Square 8
                        else {
                            if (squa_map[8].find(cell_num) != squa_map[8].end()) {
                                return false;
                            }
                            // Add cell_num to squa_map[sq_num]
                            squa_map[8][cell_num] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};

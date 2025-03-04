class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int peri = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {  // Only process land cells
                    // Check the four possible sides
                    if(j + 1 >= n || grid[i][j + 1] == 0) peri++; // Right
                    if(j - 1 < 0 || grid[i][j - 1] == 0) peri++; // Left
                    if(i + 1 >= m || grid[i + 1][j] == 0) peri++; // Down
                    if(i - 1 < 0 || grid[i - 1][j] == 0) peri++; // Up
                }
            }
        }
        return peri;
    }
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Calculate the total number of rows and columns
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Set up pointers to traverse the matrix
        int row = 0;
        int col = -1;

        // Set the initial direction to 1 for moving left to right
        int direction = 1;

        // Create an array to store the elements in spiral order
        vector<int> result;

        // Traverse the matrix in a spiral order
        while (rows > 0 && cols > 0) {

            // Move horizontally in one of two directions:
            //   1. Left to right (if direction == 1)
            //   2. Right to left (if direction == -1)
            // Increment the col pointer to move horizontally
            for (int i = 0; i < cols; i++) {
                col += direction;
                result.push_back(matrix[row][col]);
            }
            rows--;

            // Move vertically in one of two directions:
            //   1. Top to bottom (if direction == 1)
            //   2. Bottom to top (if direction == -1)
            // Increment the row pointer to move vertically
            for (int i = 0; i < rows; i++) {
                row += direction;
                result.push_back(matrix[row][col]);
            }
            cols--;

            // Flip the direction for the next traversal
            direction *= -1;
        }

        return result;
    }
};
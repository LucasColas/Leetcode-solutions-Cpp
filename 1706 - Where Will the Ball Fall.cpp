/*

You have a 2-D grid of size m x n representing a box, and you have n balls. The box is open on the top and bottom sides.

Each cell in the box has a diagonal board spanning two corners of the cell that can redirect a ball to the right or to the left.

    A board that redirects the ball to the right spans the top-left corner to the bottom-right corner and is represented in the grid as 1.
    A board that redirects the ball to the left spans the top-right corner to the bottom-left corner and is represented in the grid as -1.

We drop one ball at the top of each column of the box. Each ball can get stuck in the box or fall out of the bottom. A ball gets stuck if it hits a "V" shaped pattern between two boards or if a board redirects the ball into either wall of the box.

Return an array answer of size n where answer[i] is the column that the ball falls out of at the bottom after dropping the ball from the ith column at the top, or -1 if the ball gets stuck in the box.

https://leetcode.com/problems/where-will-the-ball-fall/

*/

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> answer(n, 0);
        for (int i = 0; i < n; i++) {
            answer[i] = findBallDrop(0,i,grid);
        }
        return answer;
        
    }
    
    int findBallDrop(int row, int col, vector<vector<int>>& grid) {
        if (row == grid.size()) {
            return col; //the ball reached the end.
            
        }
        /*
        if the ball goes to the left then grid[row][col] = -1, otherwise grid[row][col] = 1. In any case with the value grid[row][col] we know the next column.
        */
        int nextcol = col + grid[row][col]; 
        
        /*
        if we reach a wall or if we have a "V" then it's over.
        */
        if (nextcol < 0 || nextcol > grid[0].size()-1 || grid[row][col] != grid[row][nextcol]) {
            return -1;
        }
        return findBallDrop(row+1, nextcol, grid);
    }
};

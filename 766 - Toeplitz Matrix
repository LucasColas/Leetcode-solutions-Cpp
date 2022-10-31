/*
Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.
Topelitz Matrix : https://leetcode.com/problems/toeplitz-matrix/submissions/

*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if ((i-1) >= 0 && (j-1) >= 0 && matrix[i-1][j-1] != matrix[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};

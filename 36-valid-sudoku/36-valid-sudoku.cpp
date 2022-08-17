class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i)
        {
            vector<int> freq1(10, 0), freq2(10, 0), freq3(10, 0);
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] != '.') {
                    if(++freq1[board[i][j] - '0'] > 1)
                        return false;
                }
                if(board[j][i] != '.') {
                    if(++freq2[board[j][i] - '0'] > 1)
                        return false;
                }
                if(board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.') {
                    if(++freq3[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0'] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
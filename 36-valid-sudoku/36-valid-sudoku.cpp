class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                vector<int> freq(10, 0);
                for(int ii = i; ii < i+3; ++ii)
                {
                    for(int jj = j; jj < j+3; ++jj)
                    {
                        if(board[ii][jj] != '.') {
                            if(++freq[board[ii][jj] - '0'] > 1)
                                return false;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 9; ++i)
        {
            vector<int> freq1(10, 0), freq2(10, 0);
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
            }
        }
        return true;
    }
};
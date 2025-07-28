class Solution {
    private:

    bool isSafe(int newRow, int newCol, int n, int m)
    {
        if(newRow>=0 && newRow < n && newCol >= 0 && newCol < m)
        {
            return true;
        }

        return false;
    }

    bool DFS(vector<vector<bool>>&visited, vector<vector<char>>& board, string word, int row, int col, int index)
    {
        if (index == word.length()) {
            return true; // The whole word has been found
        }
        
        if (!isSafe(row, col, board.size(), board[0].size()) || visited[row][col] || board[row][col] != word[index])
         {
            return false; // Out of bounds, already visited, or mismatch
        }

        visited[row][col] = true;

        int rowNbr[4] = {-1, 0, 0, 1};
        int colNbr[4] = {0, -1, 1, 0};

        for(int i=0; i<4; i++)
        {
            int newRow = row+rowNbr[i];
            int newCol = col+colNbr[i];

            if(DFS(visited, board, word, newRow, newCol, index+1))
            {
                return true;
            }
        }

        visited[row][col] = false;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == word[0] && DFS(visited, board, word, i, j, 0) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
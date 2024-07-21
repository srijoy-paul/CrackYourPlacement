// -_-
class Solution
{

    bool check(vector<vector<char>> &board, int i, int j, string &word, int index, vector<vector<bool>> visited)
    {
        if (index == word.length() - 1)
            return true;
        visited[i][j] = true;
        if (i > 0 && !visited[i - 1][j] && board[i - 1][j] == word[index + 1] && check(board, i - 1, j, word, index + 1, visited))
            return true;
        if (j > 0 && !visited[i][j - 1] && board[i][j - 1] == word[index + 1] && check(board, i, j - 1, word, index + 1, visited))
            return true;
        if (i < board.size() - 1 && !visited[i + 1][j] && board[i + 1][j] == word[index + 1] && check(board, i + 1, j, word, index + 1, visited))
            return true;
        if (j < board[0].size() - 1 && !visited[i][j + 1] && board[i][j + 1] == word[index + 1] && check(board, i, j + 1, word, index + 1, visited))
            return true;
        visited[i][j] = false;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int i, j;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (i = 0; i < board.size(); i++)
        {
            for (j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0] && check(board, i, j, word, 0, visited))
                    return true;
            }
        }
        return false;
    }
};
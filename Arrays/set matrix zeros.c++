class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        // vector<pair<int, int>> zeroIndx;
        vector<int> row(m, 1);
        vector<int> col(n, 1);

        for (int i = 0; i < m; i++)
        { // o(m*n)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            int temp = row[i];
            if (temp == 0)
            {
                for (int k = 0; k < n; k++)
                {
                    matrix[i][k] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            int temp = col[i];
            if (temp == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    matrix[k][i] = 0;
                }
            }
        }
    }
};

// O(m*n+[l*(m+n)])
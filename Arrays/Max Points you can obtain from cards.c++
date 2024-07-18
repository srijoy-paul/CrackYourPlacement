class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int points = INT_MIN;
        int total = 0;
        int i = 0, j = n - 1;
        for (; i < k; i++)
        {
            total += cardPoints[i];
        }
        points = max(points, total);
        i--;
        while (i >= 0)
        {
            total -= cardPoints[i];
            total += cardPoints[j];
            points = max(points, total);
            i--;
            j--;
        }
        return points;
    }
};
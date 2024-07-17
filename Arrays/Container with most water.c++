class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int n = height.size();
        if (n < 2)
            return 0;
        if (n == 2)
        {
            int h = min(height[0], height[1]);
            if (h == 0)
                return 0;
            return h;
        }

        vector<int> right(n, -1);
        vector<int> left(n, -1);

        int largest = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = largest;
            if (height[largest] < height[i])
            {
                largest = i;
            }
        }
        largest = 0;
        for (int i = 1; i < n; i++)
        {
            left[i] = largest;
            if (height[largest] < height[i])
            {
                largest = i;
            }
        }
        int maxWater = INT_MIN;
        for (int i = 1; i < n - 1; i++)
        {

            int h = min(height[right[i]], height[left[i]]);
            int d = right[i] - left[i];
            maxWater = max(maxWater, h * d);
        }
        return maxWater;
    }
};
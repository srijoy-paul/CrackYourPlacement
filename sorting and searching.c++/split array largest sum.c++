class Solution
{
private:
    int count(vector<int> a, int ele, int n)
    {
        int cnt = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] + sum <= ele)
            {
                sum += a[i];
            }
            else
            {
                cnt++;
                sum = a[i];
            }
        }
        return cnt;
    }

public:
    int splitArray(vector<int> &a, int k)
    {
        int low = *(max_element(a.begin(), a.end()));
        int high = accumulate(a.begin(), a.end(), 0);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cnt = count(a, mid, a.size());
            if (cnt <= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
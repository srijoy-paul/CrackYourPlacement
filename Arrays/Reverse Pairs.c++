class Solution
{
private:
    int cnt = 0;
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        int left = low;
        int right = mid + 1;
        vector<int> temp;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.emplace_back(nums[left]);
                left++;
            }
            else
            {
                temp.emplace_back(nums[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.emplace_back(nums[left]);
            left++;
        }
        while (right <= high)
        {
            temp.emplace_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }

    void countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int right = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && (long long)nums[i] > (long long)2 * nums[right])
            {
                right++;
            }
            cnt += (right - (mid + 1));
        }
    }

    void merge_sort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid + 1, high);
        countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
    }

public:
    int reversePairs(vector<int> &nums)
    {
        merge_sort(nums, 0, nums.size() - 1);
        return cnt;
    }
};
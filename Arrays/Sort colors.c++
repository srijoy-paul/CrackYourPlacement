// approach 1
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0, one = 0, two = 0;
        for (auto num : nums)
        {
            if (num == 0)
                zero++;
            else if (num == 1)
                one++;
            else
                two++;
        }
        int i = 0;
        while (zero)
        {
            nums[i] = 0;
            i++;
            zero--;
        }
        while (one)
        {
            nums[i] = 1;
            i++;
            one--;
        }
        while (two)
        {
            nums[i] = 2;
            i++;
            two--;
        }
    }
};

// approach 2
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int l = 0, m = 0, h = nums.size() - 1;
        while (m <= h)
        {
            if (nums[m] == 0)
            {
                swap(nums[m], nums[l]);
                l++;
                m++;
            }
            else if (nums[m] == 1)
            {
                m++;
            }
            else
            {
                swap(nums[m], nums[h]);
                h--;
            }
        }
    }
};
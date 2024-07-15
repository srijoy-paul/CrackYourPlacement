class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int i = -1;
        int j = 0;
        while (j < nums.size())
        {
            if (i == -1 && nums[j] == 0)
                i = j;
            if (i != -1 && nums[j] != 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};
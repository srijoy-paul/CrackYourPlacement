class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int l = i + 1;
            int r = n - 1;
            int rem = (0 - nums[i]);
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
            {
                while (l < r)
                {
                    if (nums[l] + nums[r] == rem)
                    {
                        res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                        while (l < r && (nums[l] == nums[l + 1]))
                            l++;
                        while (l < r && (nums[r] == nums[r - 1]))
                            r--;
                        l++;
                        r--;
                    }
                    else if (nums[l] + nums[r] < rem)
                        l++;
                    else
                        r--;
                }
            }
        }
        return res;
    }
};
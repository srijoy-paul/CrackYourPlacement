class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]] = i;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (mpp.find(target - nums[i]) != mpp.end() && i != mpp[target - nums[i]])
            {
                ans.emplace_back(i);
                ans.emplace_back(mpp[target - nums[i]]);
                break;
            }
        }
        return ans;
    }
};
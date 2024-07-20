class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // int n=nums.size();
        int cnt = 0, ele;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                cnt = 1;
                ele = nums[i];
            }
            else if (ele == nums[i])
            {
                cnt++;
            }
            else
                cnt--;
        }
        cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ele)
            {
                cnt++;
            }
        }

        if (cnt > nums.size() / 2)
            return ele;
        return -1;
    }
};
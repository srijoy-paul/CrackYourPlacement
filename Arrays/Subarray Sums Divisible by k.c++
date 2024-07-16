class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {

        int count = 0;
        int sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        for (int num : nums)
        {
            sum += num;
            int rem = sum % k;
            if (rem < 0)
                rem += k;

            if (mpp.find(rem) != mpp.end())
                count += mpp[rem];

            mpp[rem]++;
        }
        return count;
    }
};
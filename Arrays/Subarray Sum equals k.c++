class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> prefixSum;
        prefixSum[0] = 1;
        int prefSum = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            prefSum += nums[i];
            int rem = prefSum - k;
            cnt += prefixSum[rem];
            prefixSum[prefSum] += 1;
        }
        return cnt;
    }
};
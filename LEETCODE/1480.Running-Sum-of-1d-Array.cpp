class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        int runningSum = 0;
        for (auto &i : nums)
        {
            runningSum += i;
            i = runningSum;
        }
        
        return nums;
    }
};
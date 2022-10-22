#include <iostream>
#include <vector>
using namespace std;

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        /*
        for each element
        STEP 2 read it's value
        store it
        and as we move ahead, we keep adding it to the value at current position, and STEP 2 again.

        */

        int store = 0;
        for (auto &i : nums)
        {
            store += i;
            i = store;
        }
        return nums;
    }
};
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int B_search(int left, int right, vector<int> &nums, int target)
    {
        if (left <= right)
        {
            int mid = (right - left) / 2 + left;

            if (nums[mid] == target)
                return mid;

            if (nums[mid] < target)
                return B_search(mid + 1, right, nums, target);

            return B_search(left, mid - 1, nums, target);
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        return B_search(0, nums.size() - 1, nums, target);
    }
};
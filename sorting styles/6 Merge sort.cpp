#include <iostream>
#include <vector>
#include <ctime>

#define RANGE 99
#define SIZE 9

class Solution
{
private:
    std::vector<int> array;

public:
    int getArraySize();
    bool insert(int v);
    void initArray()
    {
        srand(time(nullptr));

        for (int i = 0; i < SIZE; i++)
        {
            // increase range for larger numbers
            array.push_back(rand() % RANGE);
        }
    }

    void print();

    // implement method for ascending order
    //  Merge sort methods
    void mergeSort(int, int);
    void merge(int, int, int);
};

int Solution::getArraySize()
{
    return array.size();
}

void Solution::merge(int left, int middle, int right)
{
    int leftArraySize = middle - left + 1;
    int rightArraySize = right - middle;

    int *leftTEMPArray = new int[leftArraySize];
    int *rightTEMPArray = new int[rightArraySize];

    // copy the stretch into temporary arrays
    // left n right
    for (int i = 0; i < leftArraySize; ++i)
        leftTEMPArray[i] = array[left + i];
    for (int i = 0; i < rightArraySize; ++i)
        rightTEMPArray[i] = array[middle + i + 1];

    // compare both left and right sub arrays, searching for smaller element,
    // and put the smaller element using offset_for_sorted_array back to array
    int offset_for_left_array = 0;
    int offset_for_right_array = 0;
    int offset_for_sorted_array = left;

    while (offset_for_left_array < leftArraySize && offset_for_right_array < rightArraySize)
    {
        if (leftTEMPArray[offset_for_left_array] <= rightTEMPArray[offset_for_right_array])
        {
            array[offset_for_sorted_array] = leftTEMPArray[offset_for_left_array];
            ++offset_for_left_array;
        }
        else
        {
            array[offset_for_sorted_array] = rightTEMPArray[offset_for_right_array];
            ++offset_for_right_array;
        }

        ++offset_for_sorted_array;
    }

    // so far elements were inserted for lesser lengths array
    // remaining we need to manually insert.
    // one time for left array
    while (offset_for_left_array < leftArraySize)
    {
        array[offset_for_sorted_array] = leftTEMPArray[offset_for_left_array];
        ++offset_for_left_array;
        ++offset_for_sorted_array;
    }

    // one time for right array
    while (offset_for_right_array < rightArraySize)
    {
        array[offset_for_sorted_array] = rightTEMPArray[offset_for_right_array];
        ++offset_for_right_array;
        ++offset_for_sorted_array;
    }
}

void Solution::mergeSort(int begin, int end)
{
    // break recursion
    if (end <= begin)
        return;

    int middle = begin + (end - begin) / 2;

    mergeSort(begin, middle);
    mergeSort(middle + 1, end);

    // merging from here
    merge(begin, middle, end);
}

void Solution::print()
{
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    Solution obj;
    obj.initArray();

    obj.print();
    obj.mergeSort(0, obj.getArraySize() - 1);
    obj.print();
}
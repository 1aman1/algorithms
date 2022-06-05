#include <iostream>
#include <vector>

class Solution
{
private:
    std::vector<int> array;

public:
    bool insert(int v);

    void print();

    // implement method for ascending order
    void bubble_sort();
};

void Solution::print()
{
    for (auto i : array)
        std::cout << i << " ";
    std::cout << std::endl;
}

bool Solution::insert(int v)
{
    array.push_back(v);
    return true;
}

void Solution::bubble_sort()
{ // use flag for previous swap, if any

    bool ifSwappedThenContinue;
    for (int i = 0; i < array.size() - 1; ++i)
    {
        ifSwappedThenContinue = false;
        for (int j = 0; j < array.size() - 1 - i; ++j)
        {
            if (!(array[j] < array[j + 1]))
            { // swap
                array[j] = array[j] ^ array[j + 1];
                array[j + 1] = array[j] ^ array[j + 1];
                array[j] = array[j] ^ array[j + 1];
                ifSwappedThenContinue = true;
            }

            if (ifSwappedThenContinue == false)
                break;
        }
    }
}

int main()
{
    Solution obj;
    /*

        obj.insert(5);
        obj.insert(4);
        obj.insert(3);
        obj.insert(2);
        obj.insert(1);
    */

    obj.insert(1);
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(5);

    obj.print();

    obj.bubble_sort();
    obj.print();

    return 0;
}
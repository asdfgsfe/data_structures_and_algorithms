#include <iostream>
#include <vector>

bool IsOdd(int num)
{
    return num & 0x01;
}

void ReorderOfArray(vector<int>& nums)
{
    if (nums.size() < 2)
    {
        return;
    }
    for (int p = 1; p < nums.size(); ++p)
    {
        for (int i = p; i > 0 && !IsOdd(a[i - 1]) && IsOdd(a[i]); --i)
        {
            std::swap(a[i - 1], a[i]);
        }
    }
}


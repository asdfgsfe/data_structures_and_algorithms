#include <iostream>
#include <vector>

using std::vector;
//can stable
void SelectSort(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int i = 0; i < a.size(); ++i)
  {
    int minIndex = i;
    for (int j = i + 1; j < a.size(); ++j)
    {
      if (a[j] < a[minIndex])
      {
        minIndex = j;
      }
    }
    std::swap(a[minIndex], a[i]);
  }
}

//methed 2
void SelectSort2(vector<int>& nums)
{
    if (nums.size() < 2)
    {
        return;
    }
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] > nums[j])
            {
                std::swap(nums[i], nums[j]);
            }
        }
    }
}
void Dump(const vector<int>& nums)
{
    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    vector<int> nums = {2, 7, 1, 6, 3, 5, 4};
    SelectSort2(nums);
    Dump(nums);
    return 0;
}

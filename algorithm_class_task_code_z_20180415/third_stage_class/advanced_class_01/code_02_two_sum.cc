#include <iostream>
#include <vector>

void Swap(std::vector<int>& num, std::vector<int>& indices, int i, int j)
{
  int tmp = num[i];
  num[i] = num[j];
  num[j] = tmp;
  tmp = indices[i];
  indices[i] = indices[j];
  indices[j] = tmp;
}

void HeapInsert(std::vector<int>& num, std::vector<int>& indices, int child)
{
  while (child > 0)
  {
    int father = (child - 1) / 2;
    if (num[child] <= num[father])
    {
      break;
    }
    Swap(num, indices, child, father);
    child = father;
  }
}

void Heapify(std::vector<int>& num, std::vector<int>& indices, int size)
{
  int i = 0;
  int left = 1;
  int right = 2;
  int largest;
  while (left < size)
  {
    largest = num[left] > num[i] ? left : i;
    largest = right < size && num[right] > num[largest] ? right : largest;
    if (largest == i)
    {
      break;
    }
    Swap(num, indices, i, largest);
    i = largest;
    left = 2*i + 1;
    right = 2*i +2;
  }
}

void HeapSort(std::vector<int>& num, std::vector<int>& indices)
{
  for (int i = 0; i < num.size(); ++i)
  {
    HeapInsert(num, indices, i);
  }
  for (int i = num.size() - 1; i >= 0; --i)
  {
    Swap(num, indices, 0, i);
    Heapify(num, indices, i);
  }
}

std::vector<int> TwoSum(std::vector<int>& num, int target)
{
  std::vector<int> indices;
  indices.resize(num.size());
  for (int i = 0; i < num.size(); ++i)
  {
    indices[i] = i;
  }

  HeapSort(num, indices);
  
  int left = 0;
  int right = num.size() - 1;
  int sum = 0;
  std::vector<int> result = {-1, -1};
  while (left < right)
  {
    sum = num[left] + num[right];
    if (sum == target)
    {
      result[0] = left;
      result[1] = right;
      return result;
    }
    else if (sum < target)
    {
      ++left;
    }
    else
    {
      --right;
    }
  }
  return result;
}

int main(void)
{
  int a[] = {2, 7, 11, 15};
  //不支持 有重复数字的情况 需要具体再写
  int b[] = {1, 1, 2, 3, 4, 5, 5, 5};
  std::vector<int> case1 (a, a+4);
  std::vector<int> result = TwoSum(case1, 9);
  std::cout << result[0] << " " << result[1] << std::endl;

  return 0;
}



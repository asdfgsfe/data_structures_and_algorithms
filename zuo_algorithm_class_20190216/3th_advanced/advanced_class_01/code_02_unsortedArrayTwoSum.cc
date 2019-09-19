#include <iostream>
#include <vector>

using std::vector;

//未排序的数组 找到两个等于aim 
//先排序 从两边累加
void Heapify(vector<int>& numbers, int size);
void HeapSort(vector<int>& numbers);
void HeapInsert(vector<int>& numbers, int index);

vector<int> TwoSum(vector<int>& numbers, int aim)
{
  if (numbers.size() < 2)
  {
    return vector<int>();
  }
  HeapSort(numbers);
  int l = 0;
  int r = numbers.size() - 1;
  while (l < r)
  {
    int sum = numbers[l] + numbers[r];
    if (sum > aim)
    {
      --r;
    }
    else if (sum < aim)
    {
      ++l;
    }
    else
    {
      return {numbers[l], numbers[r]};
    }
  }
  return vector<int>();
}

void HeapSort(vector<int>& numbers)
{
  if (numbers.size() < 2)
  {
    return;
  }
  for (int i = 0; i < numbers.size(); ++i)
  {
    HeapInsert(numbers, i);
  }
  for (int i = numbers.size() - 1; i > 0; --i)
  {
    std::swap(numbers[0], numbers[i]);
    Heapify(numbers, i);
  }
}

void HeapInsert(vector<int>& numbers, int index)
{
  while (index > 0)
  {
    int parent = (index - 1) / 2;
    if (numbers[index] <= numbers[parent])
    {
      break;
    }
    std::swap(numbers[index], numbers[parent]);
    index = parent;
  }
}

void Heapify(vector<int>& numbers, int size)
{
  //size是一个不可达的位置
  int i = 0;
  int left = 1;
  int right = 2;
  while (left < size)
  {
    int largest = numbers[i] < numbers[left] ? left : i;
    largest = right < size && numbers[right] > numbers[largest] ? right : largest;
    if (i == largest)
    {
      break;
    }
   std::swap(numbers[i], numbers[largest]);
   i = largest;
   left = 2 * i + 1;
   right = 2 * i + 2;
  }
}


//该题的另一个解法 空间换时间的思想 用map记录
//如果要求返回累加和为aim的两个值的id 不能采用排序的思想 排序会使原来的id改变
//
vector<int> TwoSum(vector<int>& numbers, int aim)
{
	if (numbers.size() < 2)
	{
		return vector<int>();
	}
	unordered_map<int, int> numToIdxs;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numToIdxs.count(aim - numbers[i]))
		{
			//也没问题就是要返回原数字的下标 所以用了map记录
			//如果仅仅只是返回值 用unorder_set存值就行
			return {numToIdx[aim - numbers[i]], i};
		}
		numToIdxs[numbers[i]] = i;
	}
	return vector<int>();
}


int main(void)
{
  vector<int> numbers = {2, 7, 11, 15};
  int aim = 9;
  vector<int> answer = TwoSum(numbers, aim);
  std::cout << answer[0] << " " << answer[1] << std::endl;
  return 0;
}

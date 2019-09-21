#include <iostream>
#include <vector>

using std::vector;

void PercDown(vector<int>& nums, int i, int n);
//做不到稳定性
void HeapSort(vector<int>& a)
{
	if (a.size() < 2)
	{
		return;
	}
	for (int i = a.size() / 2; i >= 0; --i)
	{
        PercDown(a, i, a.size());
	}
	for (int i = a.size() - 1; i > 0; --i)
	{
		std::swap(a[0], a[i]);
		PercDown(a, 0, i);
	}
}

void PercDown(vector<int>& a, int i, int n)
{
	int child = 2 * i + 1;
	while (child < n)
	{
		child = child + 1 != n && a[child + 1] > a[child] ? child + 1 : child;
		if (a[i] >= a[child])
		{
			break;
		}
		std::swap(a[i], a[child]);
		i = child;
		child = 2 * i + 1;
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
    vector<int> nums = {2, 1, 5, 3, 4};
    HeapSort(nums);
    Dump(nums);
    return 0;
}

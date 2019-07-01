#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <assert.h>
#include <algorithm>

using std::vector;
using std::string;
using std::set;

struct Node
{
	int sum;
	int row;
	int col;
	Node(int s, int r, int c)
		: sum(s), row(r), col(c)
	{}
};

//区别在于用visited代替集合 判断重复  
//添加了边界条件的判断
vector<int> TopK(const vector<int>& arr1, const vector<int>& arr2, int k)
{
	if (k < 1)
	{
		return vector<int>();
	}
	if (arr1.empty())
	{
		return vector<int>(arr2.rbegin(), arr2.rbegin() + (k >= arr2.size() ? 0 : k));
	}
	if (arr2.empty())
	{
		return vector<int>(arr1.rbegin(), arr1.rbegin() + (k >= arr1.size() ? 0 : k));
	}
	k = std::min(k, arr1.size() * arr2.size());
	vector<Node> heap;
	heap.emplace_back(arr1.back() + arr2.back(), arr1.size() - 1, arr2.size() - 1);
	vector<vector<bool>> visited(arr1.size(), vector<bool>(arr2.size(), false));
	visited.back().back() = true;
	auto Greater = [](const Node& lhs, const Node& rhs) ->bool { return lhs.sum < rhs.sum};
	vector<int> topK(k);
	int index = 0;
	for (int i = 0; i < k; ++i)
	{
		assert(!heap.empty());
		const Node& cur = heap.front();
		topk[index++] = cur.sum;
		int curR = cur.row;
		int curC = cur.col;
		std::pop_heap(heap.begin(), heap.end(), Greater);
		heap.pop_back();
		if (curR > 0 && !visited[curR - 1][curC])
		{
			visited[curR - 1][curC] = true;
			heap.emplace_back(arr1[curR - 1] + arr2[curC], curR - 1, curC);
			std::push_heap(heap.begin(), heap.end(), Greater);
		}
		if (curC > 0 && !visited[curR][curC - 1])
		{
			visited[curR][curC - 1] = true;
			heap.emplace_back(arr1[curR] + arr2[curC - 1], curR, curC);
			std::push_heap(heap.begin(), heap.end(), Greater);
		}
	}
	return topk;
}


void PrintVector(const vector<int>& values)
{
  for (int v : values)
  {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  vector<int> a1 = {1, 2, 3, 4, 5};
  vector<int> a2 = {3, 5, 7, 9, 11};
  PrintVector(TopKSum(a1, a2, 4));

  return 0;
}

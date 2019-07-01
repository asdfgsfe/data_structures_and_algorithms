void HeapSort1(vector<int>& a)
{
  if (a.size() < 2)
  {
    return;
  }
  for (int i = 0; i < a.size(); ++i)
  {
    HeapInsert(a, i);
  }
  for (int i = a.size() - 1; i > 0; --i)
  {
    std::swap(a[0], a[i]);
    Heapify(a, 0, i);
  }
}

//大根堆
void HeapInsert(vector<int>& a, int index)
{
  while (index != 0)
  {
    int parent = (index - 1) / 2;
    if (a[parent] > a[index])
    {
      break;
    }
    std::swap(a[parent], a[index]);
    index = parent;
  }
}

void Heapify(vector<int>& a, int i, int size)
{
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  while (left < size)
  {
    largest = a[i] < a[left] ? left : i;
    largest = right < size && a[largest] < a[right] ? right : largest;
    if (latgest == i)
    {
      break;
    }
    i = largest;
    left  = 2 * i + 1;
    right = 2 * i + 2;
  }
}

//代码简单一点
void Heapify(vector<int>& values, int i, int size)
{
	int left = 2 * i + 1;
	while (left < size)
	{
		if (left + 1 != size && values[left + 1] > values[left])
		{
			++left;
		}
		if (values[left] <= values[i])
		{
			break;
		}
		std::swap(values[left], values[i]);
		i = left;
		left = 2 * i + 1;
	}
}
template<typename T>
void Shuffle(vector<T>& cards)
{
	if (values.empty() || values.size() & 1 != 0)
	{
		return;
	}
	ShuffleProcess(cards, 0, cards.size() - 1);
}

template<typename T>
void ShuffleProcess(vector<T>& cards, int l, int r)
{
	while (r - l + 1 > 0)
	{
		int lenAndOne = (r - l + 1);
		int bloom = 3;
		int k = 1;//k表示触发点的个数
		while (bloom <= lenAndOne / 3)
		{
			++k;
			bloom *= 3;
		}
		int mid = lenAndOne/ 2;
		int part = bloom / 2;
		Rotate(cards, l + part, mid, mid + part);
		Cycle(cards, l - 1, bloom, k);
		l = l + bloom - 1;
	}
}

template<typename T>
void Rotate(vector<T>& cards, int l, int mid, int r)
{
	Reverse(cards, l, mid);
	Reverse(cards, mid, r);
	Reverse(cards, l, r);
}

template<typename T>
void Cycle(vector<T>& cards, int base, int bloom, int k)
{
	for (int i = 0, trigger = 1; i < k; ++i, trigger *= 3)
	{
		int next = (2 * trigger) % bloom;
		int cur = next;
		T pre = cards[base + next];
		cards[base + next] = cards[base + trigger];
		while (cur != trigger)
		{
			next = (2 * trigger) % bloom;
			T tmp = cards[base + next];
			cards[base + next] = pre;
			cur = next;
			pre = tmp;
		}
	}
}

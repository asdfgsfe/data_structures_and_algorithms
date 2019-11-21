class Solution {
public:
	int findRotateSteps(string ring, string key) {
		if (ring.empty() || key.empty())
		{
			return 0;
		}
		return FindProcess(ring, key, 0, 0);
	}

	int FindProcess(const string& ring, const string& key, int i, int j)
	{
		if (j == key.size())
		{
			return 0;
		}
		int left = 0;
		int l = i;
		while (ring[l] != key[j])
		{
			++left;
			--l;
			l = l < 0 ? ring.size() - 1 : l;
		}
		int right = 0;
		int r = i;
		while (ring[r] != key[j])
		{
			++right;
			++r;
			r = r == ring.size() ? 0 : r;
		}
		int leftStep = left + FindProcess(ring, key, l, j + 1);
		int rightStep = right + FindProcess(ring, key, r, j + 1);
		return std::min(leftStep, rightStep)  + 1;
	}
};

//方法是错的 但是可以作为一个idea 这种记录查找的思路charToId
class Solution {
	struct Position
	{
		int left = -1;
		int right = -1;
		Position() = default;
		Position(int l, int r)
			: left(l), right(r)
		{}
	};
public:
	int findRotateSteps(string ring, string key) {
		if (ring.empty() || key.empty())
		{
			return 0;
		}
		vector<Position> charToId(256);
		for (int i = 0; i < ring.size(); ++i)
		{
			Position& pos = charToId[ring[i]];
			pos.left = pos.left == -1 ? i : pos.left;
			pos.right = std::max(pos.right, i);
		}
		return FindProcess(charToId, key, 0);
	}

	int FindProcess(const vector<Position>& charToId, const string& key, int j)
	{
		if (j == key.size())
		{
			return 0;
		}
		//错误的地方在于有多个相同的字符 不能区别出来
		const Position& pos = charToId[key[i]];
		assert(pos.left != -1 && pos.right != -1);
		int lDistance = std::abs((start == (int)ring.size() ? 0 : start) - pos.left);
		int rDistance = std::abs((start == 0 ? (int)ring.size() : start) - pos.right);
		lDistance += FindProcess(charToId, key, j + 1);
		rDistance += FindProcess(charToId, key, j + 1);
		return std::min(lDistance, rDistance)  + 1;
	}
};
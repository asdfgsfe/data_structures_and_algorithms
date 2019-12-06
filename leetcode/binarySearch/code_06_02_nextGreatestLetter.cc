class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		if (letters.empty())
		{
			return 'a';
		}
		int l = 0;
		int r = letters.size() - 1;
		int tail = -1;
		while (l <= r)
		{
			int m = l + (r - l) / 2;
			if (letters[m] <= target)
			{

				l = m + 1;
			}
			else
			{
				tail = m;
				r = m - 1;
			}
		}
		tail = tail == -1 ? 0 : tail;
		int more = letters[tail] == target ? tail + 1 : tail;
		more = more == letters.size() ? 0 : more;
		return letters[more];
	}
};
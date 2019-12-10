class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		if (rooms.empty())
		{
			return true;
		}
		vector<bool> visited(rooms.size(), false);
		queue<int> keys;
		keys.push(0);
		while (!keys.empty())
		{
			int key = keys.front();
			keys.pop();
			visited[key] = true;
			for (int k : rooms[key])
			{
				if (!visited[k])
				{
					keys.push(k);
				}
			}
		}
		for (bool v : visited)
		{
			if (!v)
			{
				return false;
			}
		}
		return true;
	}
};
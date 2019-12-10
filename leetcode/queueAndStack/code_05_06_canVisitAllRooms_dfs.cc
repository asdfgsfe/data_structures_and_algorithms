class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty())
        {
			return true;
        }
		vector<bool> visited(rooms.size(), false);
		VisitedProcess(rooms, 0, visited);
		for (bool v :  visited)
		{
			if (!v)
			{
				return false;
			}
		}
		return true;
    }

	void VisitedProcess(const vector<vector<int>>& rooms, int i, vector<bool>& visited)
	{
		if (i >= rooms.size() || visited[i])
		{
			return;
		}
		visited[i] = true;
		for (int k : rooms[i])
		{
			VisitedProcess(rooms, k, visited);
		}
	}
};
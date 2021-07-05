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



//代码简化一点
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty()) {
            return 0;
        }
        int cnt = 1;
        vector<int> visited(rooms.size(), 0);
        visited[0] = 1; //这里一定要放到外面操作
        queue<int> cans;
        cans.emplace(0);
        while (!cans.empty()) {
            int i = cans.front();
            cans.pop();
            for (int r : rooms[i]) {
                if (!visited[r]) {
                    cans.push(r);
                    visited[r] = 1; //统计cnt 和设置visited 必须放在里面 如果全部放在外面就有 重复数字出现的可能
                    ++cnt;
                }
            }
        }
        return cnt == rooms.size();
    }
};

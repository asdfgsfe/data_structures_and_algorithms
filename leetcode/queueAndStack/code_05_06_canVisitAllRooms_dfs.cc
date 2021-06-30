钥匙和房间
有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，并且房间里可能有一些钥匙能使你进入下一个房间。

在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。

最初，除 0 号房间外的其余所有房间都被锁住。

你可以自由地在房间之间来回走动。

如果能进入每个房间返回 true，否则返回 false。

示例 1：

输入: [[1],[2],[3],[]]
输出: true
解释:  
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。
示例 2：

输入：[[1,3],[3,0,1],[2],[0]]
输出：false
解释：我们不能进入 2 号房间。
提示：

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
所有房间中的钥匙数量总计不超过 3000。
相关标签
深度优先搜索
广度优先搜索
图


作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/queue-stack/gle1r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

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


//代码简单一点 可以不用遍历判断最后是否走完所有的rooms
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.empty()) {
            return 0;
        }
        int cnt = 0;
        vector<int> visited(rooms.size(), 0);
        VisitedProcess(rooms, 0, visited, cnt);
        return cnt == rooms.size();
    }

    void VisitedProcess(const vector<vector<int>>& rooms, int i, vector<int>& visited, int& cnt) {
        if (i == rooms.size() || visited[i]) {
            return;
        }
        ++cnt;
        visited[i] = 1;
        for(int r : rooms[i]) {
            VisitedProcess(rooms, r, visited, cnt);
        }
    }
};

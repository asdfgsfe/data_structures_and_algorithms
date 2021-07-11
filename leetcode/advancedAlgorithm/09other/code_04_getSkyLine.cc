class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty() || buildings[0].size() != 3) {
            return {};
        }
        vector<vector<int>> flagBuildings(buildings.size() * 2);
        for (int i = 0; i < buildings.size(); ++i) {
            flagBuildings[2 * i] = {buildings[i][0], buildings[i][2], 1};
            flagBuildings[2 * i + 1] = {buildings[i][1], buildings[i][2], 0};
        }
        std::sort(flagBuildings.begin(), flagBuildings.end(), 
            [](const vector<int>& lhs, const vector<int>& rhs) {
                return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[2] > rhs[2];
            });
        map<int, int> heightTimes;
        map<int, int> positionHeight;
        for (int i = 0; i < flagBuildings.size(); ++i) {
            int flag = flagBuildings[i][2];
            if (flag == 1) {
                ++heightTimes[flagBuildings[i][1]];
            } else {
               	auto times = heightTimes.find(flagBuildings[i][1]);
				if (times != heightTimes.end()) {
					if (--times->second == 0) {
						heightTimes.erase(times);
					}
				}
            }
            positionHeight[flagBuildings[i][0]] = heightTimes.empty() ? 0 : (heightTimes.rbegin())->first;
        }
        vector<vector<int>> skyLine;
        int p = -1;
        int h = -1;
        for (const auto& ph : positionHeight) {
            if (h == ph.second) {
                continue;
            }
            if (p != -1) {
                skyLine.emplace_back(vector<int>{p, h});
            }
            p = ph.first;
            h = ph.second;
        }
        skyLine.emplace_back(vector<int>{p, h});
        return skyLine;
    }
};

天际线问题
城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回由这些建筑物形成的 天际线 。

每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：

lefti 是第 i 座建筑物左边缘的 x 坐标。
righti 是第 i 座建筑物右边缘的 x 坐标。
heighti 是第 i 座建筑物的高度。
天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/top-interview-questions-hard/xdg3xr/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

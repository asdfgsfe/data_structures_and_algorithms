class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.empty() || points[0].empty())
        {
            return 0;
        }
        unordered_map<int, int> distanceCnt;
        int cnt = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            distanceCnt.clear();
            for (int j = 0; j < points.size(); ++j)
            {
                if (i == j)
                {
                    continue;
                }
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                int d = x * x + y * y;
                auto count = distanceCnt.find(d);
                if (count != distanceCnt.end())
                {
                    cnt += count->second * 2;
                }
                ++distanceCnt[d];
            }
        }
        return cnt;
    }
};

//尝试把每一个点都当做第一个点，然后计算与其它点的距离，并保存在hashMap中，
//若计算出的距离在hashMap中已有值，则表明之前有相同的距离，累加到count，
//由于可以换位，则乘以2.当前点作为第一个点结束之后，清空hashMap，继续以下一个点作为第一个点。

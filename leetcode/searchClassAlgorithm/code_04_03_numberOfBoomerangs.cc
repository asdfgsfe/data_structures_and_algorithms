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

//���԰�ÿһ���㶼������һ���㣬Ȼ�������������ľ��룬��������hashMap�У�
//��������ľ�����hashMap������ֵ�������֮ǰ����ͬ�ľ��룬�ۼӵ�count��
//���ڿ��Ի�λ�������2.��ǰ����Ϊ��һ�������֮�����hashMap����������һ������Ϊ��һ���㡣

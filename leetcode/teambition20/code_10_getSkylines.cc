//���������
//���е�������Ǵ�Զ���ۿ��ó��������н������γɵ��������ⲿ������
//���ڣ�����������˳��з����Ƭ��ͼA������ʾ�����н������λ�ú͸߶ȣ�
//���дһ���������������Щ�������γɵ�����ߣ�ͼB����
//
//Buildings  Skyline Contour
//
//ÿ��������ļ�����Ϣ����Ԫ��[Li��Ri��Hi] ��ʾ��
//���� Li �� Ri �ֱ��ǵ� i �����������ұ�Ե�� x ���꣬Hi ����߶ȡ�
//���Ա�֤ 0 �� Li, Ri �� INT_MAX, 0 < Hi �� INT_MAX �� Ri - Li > 0��
//�����Լ������н����ﶼ���ھ���ƽ̹�Ҹ߶�Ϊ 0 �ı����ϵ��������Ρ�
//
//���磬ͼA�����н�����ĳߴ��¼Ϊ��[[2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8]] ��
//
//�������[[x1, y1], [x2, y2], [x3, y3], ...] ��ʽ�ġ��ؼ��㡱��ͼB�еĺ�㣩���б�
//����Ψһ�ض���������ߡ��ؼ�����ˮƽ�߶ε���˵㡣
//��ע�⣬���Ҳཨ��������һ���ؼ�������ڱ������ߵ��յ㣬��ʼ��Ϊ��߶ȡ�
//���⣬�κ��������ڽ�����֮��ĵ��涼Ӧ����Ϊ�����������һ���֡�
//
//���磬ͼB�е������Ӧ�ñ�ʾΪ��[[2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0]]��
//
//˵�� :
//
//�κ������б��еĽ�����������֤��[0, 10000] ��Χ�ڡ�
//�����б��Ѿ����� x ���� Li  �����������С�
//����б���밴 x λ����
//���������в�������������ͬ�߶ȵ�ˮƽ�ߡ�
//����[...[2 3], [4 5], [7 5], [11 5], [12 7]...] �ǲ���ȷ�Ĵ𰸣�
//�����߶�Ϊ 5 ����Ӧ������������кϲ�Ϊһ����[...[2 3], [4 5], [12 7], ...]

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		if (buildings.empty() || buildings[0].empty() || buildings[0].size() != 3)
		{
			return {};
		}
		vector<vector<int>> lines(2 * buildings.size(), vector<int>(3));
		for (int i = 0; i < buildings.size(); ++i)
		{
			lines[2 * i] = { buildings[i][0], buildings[i][2], 1 };
			lines[2 * i + 1] = { buildings[i][1], buildings[i][2], 0 };
		}
		std::sort(lines.begin(), lines.end(),
			[](const auto& lhs, const auto& rhs)
		{
			return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[2] > rhs[2];
		});
		map<int, int> heightToTimes;
		map<int, int> positionToMaxHeight;
		for (int i = 0; i < lines.size(); ++i)
		{
			if (lines[i][2])
			{
				++heightToTimes[lines[i][1]];
			}
			else
			{
				auto times = heightToTimes.find(lines[i][1]);
				if (times != heightToTimes.end())
				{
					if (--times->second == 0)
					{
						heightToTimes.erase(times);
					}
				}
			}
			positionToMaxHeight[lines[i][0]] = heightToTimes.empty() ? 0 : heightToTimes.rbegin()->first;
		}
		vector<vector<int>> skyLines;
		int start = -1;
		int height = -1;
		for (auto& pmh : positionToMaxHeight)
		{
			int p = pmh.first;
			int h = pmh.second;
			if (height != h)
			{
				if (start != -1)
				{
					vector<int> line{ start, height };
					skyLines.emplace_back(std::move(line));
				}
				start = p;
				height = h;
			}
		}
		vector<int> line{ start, height };
		skyLines.emplace_back(std::move(line));
		return skyLines;
	}
};
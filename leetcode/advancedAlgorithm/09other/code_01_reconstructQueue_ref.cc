class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty() || people[0].size() != 2)
        {
            return {};
        }
        std::sort(people.begin(), people.end(),
                  [](const auto& lhs, const auto& rhs)
                  {
                      return lhs[0] != rhs[0] ? lhs[0] > rhs[0] : lhs[1] < rhs[1];
                  });
        list<vector<int>> output;
        for (const vector<int>& p : people)
        {
            auto pos = output.begin();
            for (int i = 0; i < p[1]; ++i)
            {
                ++pos;
            }
            output.insert(pos, p);
        }
        return vector<vector<int>>(output.begin(), output.end());
    }
};

//h�Ӵ�С�� h��� k��С������
//Ȼ����� ������people ��k��ֵp[1]�������� ���Ѿ��������������ǰ����� ���Ǵ�
//����ߵ��˰��� k ֵ��������Ȼ�����Ƿ��õ������������ k ֵ��ȵ�����λ���ϡ�

//�ο����
//������ȡ��һ���߶ȣ�ͬ���� k ֵ�Ը���ߵ�����������Ȼ��������뵽����������� k ֵ��ȵ�����λ���ϡ�
//ֱ�����Ϊֹ��
//���ӣ�https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/gen-ju-shen-gao-zhong-jian-dui-lie-by-leetcode/
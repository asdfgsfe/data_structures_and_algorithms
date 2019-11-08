�Ӽ�
����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

˵�����⼯���ܰ����ظ����Ӽ���

ʾ��:

����: nums = [1,2,3]
���:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

class Solution {
public:
    // ѭ������:
    // ����ֱ�ӴӺ����������һ�����Ͱ������Ӽ����ϸ�������µ��Ӽ���������ϼ��������Ӽ�
    // Ԫ����0����Ӧ[], Ԫ����1, ��Ӧ[]��[1], Ԫ����2����Ӧ[]��[1]��[2]��[1,2]��
    // ÿ��һ��Ԫ��, �����Ӽ� = ֮ǰ�����Ӽ� + ֮ǰ�����Ӽ��ӵ�ǰԪ���γɵ����Ӽ�
    // λͼ��:
    // �����N��Ԫ�أ����0~2^N-1ѭ���������ǰѭ�������ĵ�i��bitλΪ1����ѵ�i��Ԫ�ؼӽ���ǰ�Ӽ�
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result = {{}};
        //result.push_back(vector<int>{});
        for(auto var : nums)
		{
            int tmpLen = result.size();
            for(int i = 0; i < tmpLen; ++i)
			{
                vector<int> tmp = result[i];
                tmp.push_back(var);
                result.push_back(tmp);
            }
        }
        return result;
    }
};
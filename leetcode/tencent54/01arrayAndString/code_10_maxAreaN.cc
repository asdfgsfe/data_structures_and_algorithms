���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ��
�������ڻ� n ����ֱ�ߣ���ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0)��
�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��

˵�����㲻����б�������� n ��ֵ����Ϊ 2��



ͼ�д�ֱ�ߴ����������� [1,8,6,2,5,4,8,3,7]���ڴ�����£������ܹ�����ˮ����ʾΪ��ɫ���֣������ֵΪ 49��

 

ʾ��:

����: [1,8,6,2,5,4,8,3,7]
���: 49

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size() < 2)
		{
			return 0;
		}
		int area = 0;
		int l = 0;
		int r = height.size() - 1;
		while (l < r)
		{
			area = std::max(area, std::min(height[l], height[r]) * (r - l));
			if (height[l] < height[r])
			{
				++l;
			}
			else
			{
				--r;
			}
		}
		return area;
	}
};
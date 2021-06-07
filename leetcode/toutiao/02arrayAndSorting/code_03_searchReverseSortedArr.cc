//������ת��������
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��

����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��

����Լ��������в������ظ���Ԫ�ء�

����㷨ʱ�临�Ӷȱ����� O(log n) ����

ʾ�� 1:

����: nums = [4,5,6,7,0,1,2], target = 0
���: 4
ʾ�� 2:

����: nums = [4,5,6,7,0,1,2], target = 3
���: -1

//perfect ���ò��ֶ��ֲ��ҵ�˼�� ��ȷ����Χ ��ȷ����ȷ����С��Χ
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return -1;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + ((r - l) >> 1); //�����������Ҫ �ܽ�Լһ���ʱ��
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] >= nums[l]) //ȷ����Χ ������� =�ź���Ҫ
            {
                //������������ ��Ϊ����ȷ������������߰��һ������ =�ź���Ҫ
				if (nums[l] <= target && target <= nums[m])
                {
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
            else //��Χ�ұ�����
            {
				//�ұ�����ĺ��α�Ȼ���� �����=�ź���Ҫ
				if (nums[m] <= target && target <= nums[r])
                {
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};



//lowһ����뷨 ������������ ���ҵ��м�� �ڶ���
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        if (nums.front() < nums.back()) //û������
        {
            return BinSearch(nums, 0, nums.size() - 1, target);
        }
        int rIdx = ReverseIdx(nums);//�ҵ��м��
        assert(nums.front() >= nums.back());
        if (target >= nums[0])//�����
        {
            return BinSearch(nums, 0, rIdx - 1, target);
        }
        return BinSearch(nums, rIdx, nums.size() - 1, target);//�Ұ���
    }
    
    int ReverseIdx(const vector<int>& nums)
    {
        if (nums.empty())
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return 0;
        }
        int l = 0;
        int r = nums.size() - 1;
        while (nums[l] > nums[r])
        {
            if (r - l == 1)
            {
                return r;
            }
            int m = (l + r) / 2;
            if (nums[m] > nums[l])
            {
                l = m;
            }
            else if (nums[m] < nums[r])
            {
                r = m;
            }
        }
        return l;
    }
    
    int BinSearch(const vector<int>& nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (nums[m] == target)
            {
                return m;
            }
            else if (nums[m] > target)
            {
                --r;
            }
            else
            {
                ++l;
            }
        }
        return -1;
    }
};

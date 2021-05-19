����֮��
����һ������ n ������������ nums���ж� nums ���Ƿ��������Ԫ�� a��b��c ��ʹ�� a + b + c = 0 ��
�ҳ��������������Ҳ��ظ�����Ԫ�顣

ע�⣺���в����԰����ظ�����Ԫ�顣

����, �������� nums = [-1, 0, 1, 2, -1, -4]��

����Ҫ�����Ԫ�鼯��Ϊ��
[
  [-1, 0, 1],
  [-1, -1, 2]
]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return vector<vector<int>>();
        }
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> sums;
        //�̶�a���� ��������������b+c
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    vector<int> tmp{nums[i], nums[l++], nums[r--]};
                    sums.emplace_back(std::move(tmp));
                    while (l < r && nums[l] == nums[l - 1]) { ++l; }
                    while (l < r && nums[r] == nums[r + 1]) { --r; }
                }
                else if (sum < 0)
                {
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) { ++l; }
                }
                else
                {
                    --r;
                    while (l < r && nums[r] == nums[r + 1]) { --r; }
                }
            }
        }
        return sums;
    }
};

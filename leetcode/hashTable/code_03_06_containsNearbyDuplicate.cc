//�����ظ�Ԫ�� II
class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty())
		{
			return false;
		}
		unordered_set<int> klen;
		// i - j�ľ���ֵС�ڵ���k ���ù̶����ȵ�set
		// ��������ģ�� �̶����ȵĴ���
		for (int i = 0; i < nums.size(); ++i)
		{
			if (klen.count(nums[i]))
			{
				return true;
			}
			klen.emplace(nums[i]);
			if (klen.size() > k)
			{
				//���ڳ���̫�� ɾ���������ڵ�ֵ 
				//���ظ�ֵ����ν ��Ϊ�ظ�ֵ����Ǵ� ǰ��϶��Ѿ��ҹ���
				klen.erase(nums[i - k]);
			}
		}
		return false;
	}
};

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		if (nums.empty())
		{
			return false;
		}
		//����map
		unordered_map<int, int> numToIds;
		for (int i = 0; i < nums.size(); ++i)
		{
			auto id = numToIds.find(nums[i]);
			if (id != numsToIds.end() && i - id->second <= k)
			{
				return true;
			}
			//����Ҫ��i-j<=k ���Դ������һ��i
			//��Щ��ĿҪ���>= ��Ҫ����Զ��һ��
			numsToIds[nums[i]] = i;
		}
		return false;
	}
};

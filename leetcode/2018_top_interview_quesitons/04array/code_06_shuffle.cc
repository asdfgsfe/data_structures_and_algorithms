//�������� Fisher-Yates ϴ���㷨 ��ͨ����
//˼·
//���ǿ�����һ���򵥵ļ���������֮ǰ�㷨��ʱ�临�ӶȺͿռ临�Ӷȣ�
//�Ǿ����������е�Ԫ�ػ��ཻ���������Ϳ��Ա����ÿ�ε����������޸��б��ʱ���ˡ�
//�㷨
//Fisher-Yates ϴ���㷨�������㷨����
//��ÿ�ε����У�����һ����Χ�ڵ�ǰ�±굽����ĩβԪ���±�֮������������
//������������ǰԪ�غ����ѡ�����±���ָ��Ԫ�ػ��ཻ�� - ��һ��ģ����ÿ�δ� ��ñ�ӡ� ������һ��Ԫ�صĹ��̣�
//����ѡȡ�±귶Χ����������ÿ����������Ԫ�ض��������ٱ��������ˡ�
//���⻹��һ����Ҫע���ϸ�ڣ���ǰԪ���ǿ��Ժ��������ཻ���� - ������������������ϵĸ��ʾͲ����ˡ�
//Ϊ�˸�����������һ���̣����Կ�������Щ������

//���ӣ�https://leetcode-cn.com/problems/shuffle-an-array/solution/da-luan-shu-zu-by-leetcode/

class Solution {
public:
	Solution(vector<int> nums) {
		original_ = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return original_;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> nums = original_;
		for (int i = 1; i < nums.size(); ++i)
		{
			int r = rand() % (i + 1);
			swap(nums[r], nums[i]);
		}
		return nums;
	}

private:
	vector<int> original_;
};

//����һ�� ���� ��ͨ����
//˼·
//�������ǰ�ÿ����������һ�� ��ñ�ӡ� ���棬Ȼ�����Ǵ�ñ�����������һ������������
//������������˳��������飬����������þ�������Ҫ��ϴ�ƺ�����顣
//�㷨
//�����㷨�򵥵���˵���ǰ�ÿ��������һ�� ��ñ�ӡ� ���棬ÿ�δ� ��ñ�ӡ� ���������һ����������
//ֱ�� ��ñ�ӡ� Ϊ�ա������Ǿ���������������ǰ����� array ����һ�ݸ����� aux��֮��ÿ������� aux ��ȡһ������
//Ϊ�˷�ֹ�����ظ�ȡ����ÿ��ȡ��Ͱ�������� aux ���Ƴ���
//���� ��ʵ�ַ�ʽ�ܼ򵥣�ֻ��� array �ָ����ʼ��״̬�Ϳ����ˡ�

class Solution {
    private int[] array;
    private int[] original;

    private Random rand = new Random();

    private List<Integer> getArrayCopy() {
        List<Integer> asList = new ArrayList<Integer>();
        for (int i = 0; i < array.length; i++) {
            asList.add(array[i]);
        }
        return asList;
    }

    public Solution(int[] nums) {
        array = nums;
        original = nums.clone();
    }
    
    public int[] reset() {
        array = original;
        original = original.clone();
        return array;
    }
    
    public int[] shuffle() {
        List<Integer> aux = getArrayCopy();

        for (int i = 0; i < array.length; i++) {
            int removeIdx = rand.nextInt(aux.size());
            array[i] = aux.get(removeIdx);
            aux.remove(removeIdx);
        }

        return array;
    }
}
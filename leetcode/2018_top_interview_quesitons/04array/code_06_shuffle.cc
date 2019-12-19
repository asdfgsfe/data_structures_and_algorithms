//方法二： Fisher-Yates 洗牌算法 【通过】
//思路
//我们可以用一个简单的技巧来降低之前算法的时间复杂度和空间复杂度，
//那就是让数组中的元素互相交换，这样就可以避免掉每次迭代中用于修改列表的时间了。
//算法
//Fisher-Yates 洗牌算法跟暴力算法很像。
//在每次迭代中，生成一个范围在当前下标到数组末尾元素下标之间的随机整数。
//接下来，将当前元素和随机选出的下标所指的元素互相交换 - 这一步模拟了每次从 “帽子” 里面摸一个元素的过程，
//其中选取下标范围的依据在于每个被摸出的元素都不可能再被摸出来了。
//此外还有一个需要注意的细节，当前元素是可以和它本身互相交换的 - 否则生成最后的排列组合的概率就不对了。
//为了更清楚地理解这一过程，可以看下面这些动画：

//链接：https://leetcode-cn.com/problems/shuffle-an-array/solution/da-luan-shu-zu-by-leetcode/

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

//方法一： 暴力 【通过】
//思路
//假设我们把每个数都放在一个 ”帽子“ 里面，然后我们从帽子里面把它们一个个摸出来，
//摸出来的数按顺序放入数组，这个数组正好就是我们要的洗牌后的数组。
//算法
//暴力算法简单的来说就是把每个数放在一个 ”帽子“ 里面，每次从 ”帽子“ 里面随机摸一个数出来，
//直到 “帽子” 为空。下面是具体操作，首先我们把数组 array 复制一份给数组 aux，之后每次随机从 aux 中取一个数，
//为了防止数被重复取出，每次取完就把这个数从 aux 中移除。
//重置 的实现方式很简单，只需把 array 恢复称最开始的状态就可以了。

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
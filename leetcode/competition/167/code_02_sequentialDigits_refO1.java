思路：根据参数low和high的位数构造符合位数范围的顺次数，时间复杂度和low和high的位数大小有关，
也算时间复杂度为o(1)吧，但代码可读性不怎么好，大家多指正。

class Solution {
    public List<Integer> sequentialDigits(int low, int high) {
		//返回值
		List<Integer> result = new ArrayList<>();
		//存储两个阈值的位数
		int lowBits = 0, highBits = 0;
		//将参数的值留备份
		int low2 = low, high2 = high;
		//求位数
		while (low != 0) {
			lowBits++;
			low = low / 10;
		}
		while (high != 0) {
			highBits++;
			high = high / 10;
		}
		//思路：根据左右阈值的位数构造出符合条件的顺次数
		//首先将构造的数限制在参数的位数范围内
		for (int i = lowBits; i <= highBits; i++) {
			int value = 0;
			//k代表每一位的可能取值，1到9 用于生成12345 23456的数字
			for (int k = 1; k <= 9; k++) {
				//提前退出循环的标志
				boolean flag = false;
				//根据顺次数的要求，下一位的取值为上一位+1，故要求index自增1
				int index = k;
				//j控制位数
				for (int j = i; j > 0; j--) {
					//若遍历过程中取值大于9，则退出循环
					if (index > 9) {
						flag = true;
						break;
					}
					//位数改变后需要修改value的值
					value = value * 10 + index;
					//下一位数的值自增1
					index++;
				}
				//若位数符合条件且构造的顺次数在参数范围内，则添加到返回值集合中
				//优化的地方在于从固定长度的位数的最小值开始去开始遍历 利用是否在[low, high]内判断该数字合法
				if (!flag && (value >= low2 && value <= high2)) {
					result.add(value);
				}
				//清零，不影响构造下一个顺次数
				value = 0;
			}
		}
		return result;
	}
}
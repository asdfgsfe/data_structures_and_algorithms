//在LR字符串中交换相邻字符
//在一个由 'L', 'R' 和 'X' 三个字符组成的字符串（例如"RXXLRXRXL"）中进行移动操作。
//一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。+
//现给定起始字符串start和结束字符串end，请编写代码，当且仅当存在一系列移动操作使得start可以转换成end时， 返回True。
//
//示例 :
//
//输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
//	输出 : True
//	解释 :
//我们可以通过以下几步将start转换成end:
//	RXXLRXRXL ->
//		XRXLRXRXL ->
//		XRLXRXRXL ->
//		XRLXXRRXL ->
//		XRLXXRRLX
//		注意 :
//
//	1 <= len(start) = len(end) <= 10000。
//		start和end中的字符串仅限于'L', 'R'和'X'。


//注意本体L只能向左移动 R只能向右移动
class Solution
{
public:
	bool canTransform(string start, string end) {
		if (start.size() != end.size())
		{
			return false;
		}
		int i = 0;
		int j = 0;
		while (i < start.size() && j < end.size())
		{
			while (start[i] == 'X')
			{
				++i;
			}
			while (end[j] == 'X')
			{
				++j;
			}
			//如果这俩个非X字符不同，则剔除掉X之后的串必然不同，所以是错的。
			if (start[i] != end[j])
			{
				return false;
			}
			//同为L，但在start的位置先于其在end串的位置，也是错的，L不能后移
			if (start[i] == 'L' && i < j)
			{
				return false;
			}
			if (start[i] == 'R' && i > j)
			{
				return false;
			}
			++i;
			++j;
		}
		return true;
	}
};
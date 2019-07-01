#include <iostream>

//在第一条折痕的基础上在折一次 在第一个折痕的上下都会出现一个折痕
//在第二次折痕的基础上在折一次 每条折痕的两侧均会出现折痕 想到二叉树的情形
//按照层中序遍历 设n层 二叉树总共二的n次方-1个节点
void PrintProcess(int level, int n, int down)
{
  if (level > n)
  {
    return;
  }
  PrintProcess(level + 1, n, true);
  std::cout << "level=" << level << " " <<(down ? "down" : "up") << std::endl;
  PrintProcess(level + 1, n, false);
}

void PrintAllFolds(int n)
{
  if (n < 1)
  {
    return;
  }
  PrintProcess(1, n, true);
}


void PrintProcess2(int n, bool down)
{
	if (n == 0)
	{
		return;
	}
	PrintProcess(n - 1, true);
	std::cout << (down ? "down" : "up") << std::endl;
	PrintProcess(n - 1, false);
}

void PrintAllFolds2(int n)
{
	if (n > 0)
	{
		PrintProcess2(n, true);
	}
}

int main(void)
{
  int n = 4;
  PrintAllFolds(n);
  std::cout << std::endl;
  PrintAllFolds2(n);
  return 0;
}

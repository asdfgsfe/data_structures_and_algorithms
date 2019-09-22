#include <iostream>

//错误的方法 由于a没有变化 
int Add(int a, int b)
{
	int sum = a;
	while (b)
	{
		sum ^= b;
		b = (a & b) << 1;
	}
	return sum;
}

int Add2(int a, int b)
{
    while (b)
    {
        int tmp = a ^ b;
        b = (a & b) << 1;
        a = tmp;
    }
    return a;
}

int main(void)
{
    std::cout << (4 + 2) << " " << Add(4, 2) << " " << Add2(4, 2) << std::endl;
    std::cout << (8 + 7) << " " << Add(8, 7) << " " << Add2(7, 8) << std::endl;
    
    std::cout << (124 + 1332) << " " << Add(124, 1332) << " " << Add2(124, 1332) << std::endl;
    std::cout << (49999 + 223455) << " " << Add(49999, 223455) << " " << Add2(49999, 223455) << std::endl;
    
    return 0;
}

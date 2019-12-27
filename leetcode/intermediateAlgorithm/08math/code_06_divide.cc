 class Solution {
 public:
	 int divide(int dividend, int divisor) {
		 if (divisor == 0)
		 {
			 return 0x7fffffff;
		 }
		 if (divisor == -1) 
		 {
			 // 只要不是最小的那个整数，都是直接返回相反数就好啦
			 if (dividend > INT_MIN)
			 {
				 return -dividend;
			 }
			return INT_MAX;// 是最小的那个，那就返回最大的整数啦
		 }
		 return DoDiv(dividend, divisor);
	 }

	 int DoDiv(int dividend, int divisor)
	 {
		 long long x = dividend;
		 long long y = divisor;
		 x = x < 0 ? -x : x;
		 y = y < 0 ? -y : y;
		 unsigned int ret = 0;
		 for (int i = 31; i >= 0; i = Sub(i, 1))
		 {
			 if ((x >> i) >= y)
			 {
				 ret |= (1 << i);
				 x = Sub(x, y << i);
			 }
		 }
		 return (dividend > 0) ^ (divisor > 0) ?  Negative(ret) : ret;
	 }

	 long long Sub(long long a, long long b)
	 {
		 return Add(a, Negative(b));
	 }

	 long long Negative(long long a)
	 {
		 return Add(~a, 1);
	 }

	 long long Add(long long a, long long b)
	 {
		 while (b)
		 {
			 long long c = ((unsigned long long)a & b) << 1;
			 a = a ^ b;
			 b = c;
		 }
		 return a;
	 }
 };
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
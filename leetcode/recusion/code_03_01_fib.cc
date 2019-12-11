class Solution {
public:
    int fib(int N) {
        if (N < 2)
        {
            return N;
        }
        return fib(N - 1) + fib(N - 2);
    }
};



class Solution {
public:
    int fib(int N) {
        if (N < 2)
        {
            return N;
        }
        int f0 = 0;
		int f1 = 1;
		int f2;
		for (int i = 2; i <= N; ++i)
		{
			f2 = f1 + f0;
			f0 = f1;
			f1 = f2;
		}
		return f2;
    }
};
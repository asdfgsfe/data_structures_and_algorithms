void PaperFolding(int n)
{
	if (n < 1)
	{
		return;
	}
	PrintProcess(n, true);
}

void PrintProcess(int n, bool isDown)
{
	if (n == 0)
	{
		return;
	}
	PrintProcess(n - 1, true);
	std::cout << "n=" << n << " " <<(isDown ? "down" : "up") << std::endl;
	PrintProcess(n - 1, false);
}


//Ö±½ÓµÝ¹é´òÓ¡
void PaperFolding(int n, bool up)
{
	if (n < 0)
	{
		return;
	}
	PaperFolding(n - 1, true);
	std::cout << (up ? "up" : "down") << std::endl;
	PaperFolding(n - 1, false);
}
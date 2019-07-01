void FoundChar(const string& str1, const string& str2)
{
	if (str1.empty() || str2.empty())
	{
		return;
	}
	TrieTree trieTree;
	trieTree.Insert(str1);
	for (char ch : str2)
	{
		if (trieTree.Search(ch))
		{
			std::cout << ch << " ";
		}
	}
	std::cout << std::endl;
}
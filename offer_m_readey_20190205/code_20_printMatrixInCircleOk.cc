void PrintMatrix(const vector<vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return 0;
    }
    int ra = 0;
    int ca = 0;
    int rb = matrix.size() - 1;
    int cb = matrix.back().size() - 1;
    while (ra <= rB && ca <= cb)
    {
        PrintEdge(matrix, ra++, ca++, rb--, cb--);
    }
}

void PrintEdge(const vector<vector<int>>& matrix, int ra, int ca, int rb, int cb)
{
    if (ra == rb)
    {
        while (ca <= cb)
        {
            std::cout << m[ra][ca++] << " ";
        }
        std::cout << std::endl;
       return;
    }
    if (ca == cb)
    {
        while (ra <= rb)
        {
            std::cout << matrix[ra++][rc] << " ";
        }
        std::cout << std::endl;
        return;
    }
    int r = ra;
    int c = ca;
    while (c < cb)
    {
        std::cout << m[r][c++] << " ";
    }
    while (r < rb)
    {
        std::cout << m[r++][c] << " ";
    }
    while (c > ca)
    {
        std::cout << m[r][c--] << " ";
    }
    while (r > ra)
    {
        std::cout << m[r--][c] << " ";
    }
    std::cout << std::endl;
}

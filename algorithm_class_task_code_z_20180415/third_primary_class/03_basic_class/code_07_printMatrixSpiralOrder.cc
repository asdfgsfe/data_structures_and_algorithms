#include <iostream>
#include <vector>

using namespace std;


void PrintEdge(const vector<vector<int> >& matrix, int row1, int row2, int col1, int col2)
{
    if (row1 == row2)
    {
        while (col1 <= col2)
        {
            cout << matrix[row1][col1++];
        }
    }
    else if (col1 == col2)
    {
        while (row1 <= row2)
        {
            cout << matrix[row1++][col1];
        }
    }
    else
    {
        int currRow = row1;
        int currCol = col1;
        while (currCol != col2)
        {
            cout << matrix[row1][currCol++];
        }

        while (currRow != row2)
        {
            cout << matrix[currRow++][col2];
        }

        while (currCol != col1)
        {
            cout << matrix[row2][currCol--];
        }

        while (currRow != row1)
        {
            cout << matrix[currRow--][col1];
        }
    }
}

void SpiralOrderMatrix(const vector<vector<int> >& matrix)
{
    int rows = matrix.size() - 1;
    int cols = matrix[0].size() - 1;
    int row = 0;
    int col = 0;
    while (row <= rows && col <= cols)
    {
        PrintEdge(matrix, row++, rows--, col++, cols--);
    }
}

int main(void)
{
    vector<vector<int> > matrix;
    for (int i = 0; i < 4; ++i)
    {
        vector<int>v;
        for (int j = 1; j < 4; ++j)
        {
            v.push_back(j);
        }
        matrix.push_back(v);
        v.clear();
    }

    SpiralOrderMatrix(matrix);
    cout << endl;
    return 0;
}
